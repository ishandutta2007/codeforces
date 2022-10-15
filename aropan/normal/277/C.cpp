#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

#define fs first
#define sc second

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }

vector < pair < int, pair <int, int> > > v;
set <int> s;
int n, m, k;
 
int main()
{
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < k; i++)
	{
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		if (x1 > x2)
			swap(x1, x2);
		if (y1 > y2)
			swap(y1, y2);
		if (x1 == x2)
			v.push_back(make_pair(x1 * 2, make_pair(y1, y2)));
		else
			v.push_back(make_pair(y1 * 2 + 1, make_pair(x1, x2)));
	}
	
	sort(v.begin(), v.end());
	
	int N = n - 1, M = m - 1;
	
	
	int res = 0;
	for (int i = 0, j = 0; i < (int)v.size(); i = j)
	{
		int last = 0;
		int x = 0;
		while (j < (int)v.size() && v[i].fs == v[j].fs)
		{
			if (last < v[j].sc.fs)
				x += v[j].sc.fs - last;
			last = max(last, v[j].sc.sc);
			j++;
		}
		int l = (v[i].fs & 1)? n : m;
		if (last < l)
			x += l - last;
		res ^= x;
		
		if (v[i].fs & 1)
			M--;
		else
			N--;
		s.insert(v[i].fs);
	}
	if (N & 1)
		for (int i = 1; i < n; i++)
			if (s.find(2 * i) == s.end())
			{
				res ^= m;
				v.push_back(make_pair(2 * i, make_pair(0, 0)));
				break;
			}
	if (M & 1)
		for (int i = 1; i < m; i++)
			if (s.find(2 * i + 1) == s.end())
			{
				res ^= n;
				v.push_back(make_pair(2 * i + 1, make_pair(0, 0)));
				break;
			}
	if (res == 0)
	{
		puts("SECOND");
		return 0;
	}
	puts("FIRST");
	for (int i = 0, j = 0; i < (int)v.size(); i = j)
	{
		int last = 0;
		int x = 0;
		while (j < (int)v.size() && v[i].fs == v[j].fs)
		{
			if (last < v[j].sc.fs)
				x += v[j].sc.fs - last;
			last = max(last, v[j].sc.sc);
			j++;
		}
		int l = (v[i].fs & 1)? n : m;
		if (last < l)
			x += l - last;
			
		if ((res ^ x) < x)
		{
			int y = x - (res ^ x);
			int last = 0;
			int x = 0;
			j = i;
			int ans = -1;
			while (j < (int)v.size() && v[i].fs == v[j].fs)
			{
				if (last < v[j].sc.fs)
				{
					x += v[j].sc.fs - last;
					if (x >= y)
					{
						ans = v[j].sc.fs - (x - y);
						break;
					}
				}
				last = max(last, v[j].sc.sc);
				j++;
			}
			int l = (v[i].fs & 1)? n : m;
			if (last < l)
				x += l - last;
				
			if (ans == -1)
				ans = l - (x - y);
			if (v[i].fs & 1)
				cout << 0 << " " << v[i].fs / 2 << " " << ans << " " << v[i].fs / 2 << endl;
			else
				cout << v[i].fs / 2 << " " << 0 << " " << v[i].fs / 2 << " " << ans << endl;
			break;
		}
	}
	return 0;
}