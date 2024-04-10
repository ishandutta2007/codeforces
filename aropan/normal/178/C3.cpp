#include <cstdio>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>
#include <ctime>
#include <cstring>
#include <algorithm>

using namespace std;


const int MAXH = 200007;


inline int prev(int x) { return (x & (x - 1)); }
inline int next(int x) { return (x | (x - 1)) + 1; }

class mhashtable
{
private:
	int n;
	vector <int> a;
	map <int, int> m;

	void modify(int x, int d)
	{
		for (int i = x; i; i = prev(i))
			a[i] += d;
	}

	int sum(int l, int r)
	{
		if (r == n)
		{
			int res = 0;
			for (int i = l; i <= n; i = next(i))
				res += a[i];
			return res;
		}
		else
		{
			return sum(l, n) - sum(r + 1, n);
		}
	}

public:
	mhashtable(int size = 0) : n(size)
	{
		a.resize(size + 1);
		m.clear();
	}

	int add(int id, int x)
	{
		int X = x;

		if (sum(x, n) == n - x + 1)
			x = 1;
/*
		int l = x, r = n;
		while (l < r)
		{
			int t = (l + r) / 2;
			if (sum(x, t) == t - x + 1)
				l = t + 1;
			else
				r = t;
		}
		x = l;
//*/
//*
		while (a[x] == next(x) - x)
			x = next(x);
//		printf("%d\n", x);

		int s = a[x];
		int l = next(x) - x;
		while (l > 1)
		{
			l /= 2;
			if (x + l > n) continue;
//			printf("\tx%d s%d l%d a%d\n", x, s, l, a[x + l]);
			if (s - a[x + l] == l)
			{
				x += l;
				s = a[x];
			}
			else
			{
				s -= a[x + l];
			}
		}
//*/
//		printf("m[%d] = %d\n", id, x);
		modify(m[id] = x, 1);
		int res = x - X;
		if (res < 0) res += n;
//		printf("%d -> %d = %d\n", X, x, res);
//		printf("%d\n", res);
		return res;
	}

	void rmv(int id)
	{
//		printf("- m[%d] = %d\n", id, m[id]);
		modify(m[id], -1);
		m.erase(id);
	}
};

vector <mhashtable> t;
pair <int, int> p[MAXH];
bool flag[MAXH];
int H, M, n;
map <int, int> hash;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif
    scanf("%d %d %d\n", &H, &M, &n);
    for (int i = 0; i < H; i++)
    	if (!flag[i])
    	{
    		int x = i, j = 0;
    		while (!flag[x])
    		{
    			j++;
    			flag[x] = true;
    			p[x] = make_pair(t.size(), j);
    			x += M;
    			if (x >= H) x -= H;
    		}
    		t.push_back(mhashtable(j));
    	}
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
    	char com;
    	int id, h;
    	scanf("%c", &com);
    	switch (com)
    	{
    		case '+':
    			scanf("%d %d\n", &id, &h);
    			ans += t[p[h].first].add(id, p[h].second);
    			hash[id] = h;
    		break;

    		case '-':
    			scanf("%d\n", &id);
    			h = hash[id];
    			hash.erase(id);
				t[p[h].first].rmv(id);
    		break;
    	}
    }
    cout << ans << endl;
    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}