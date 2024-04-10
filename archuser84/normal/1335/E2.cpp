#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) (flag? "YES\n": "NO\n")
#define all(x) x.begin(),x.end()
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
#define Bit(x,k) ((x >> k) & 1)
using namespace std;

const int N = 200000;
const int A = 200;

class maxHeap
{
private:
	int t[A];
	int v[A];
	int p[A];

	int left(int k) { return 2 * k + 1; }
	int right(int k) { return 2 * k + 2; }
	int parent(int k) { return (k - 1) / 2; }
public:
	void reset()
	{
		Loop(i, 0, A)
		{
			p[i] = i;
			t[i] = i;
			v[i] = Mod1 + 1;
		}
	}

	void heapify(int k)
	{
		int m = k;
		int l = left(k);
		int r = right(k);
		if (l < A && v[t[l]] > v[t[m]])
			m = l;
		if (r < A && v[t[r]] > v[t[m]])
			m = r;
		if (m != k)
		{
			swap(p[t[m]], p[t[k]]);
			swap(t[m], t[k]);
			heapify(m);
		}
	}
	int getMax() { return v[t[0]]; }
	void decreaseSet(int k, int newv)
	{
		v[k] = newv;
		heapify(p[k]);
	}
	void decrease(int k)
	{
		decreaseSet(k, v[k] - 1);
	}
};

int a[N];
int cnt[A];
int n;
maxHeap H;

int Solve(int x)
{
	H.reset();
	Loop(i, 0, A)
		H.decreaseSet(i, cnt[i]);
	H.decreaseSet(x, 0);
	int l = 0, r = n - 1;
	int ans = 0;
	int k = 1;
	while (true)
	{
		while (a[l] != x) { H.decrease(a[l++]); }
		while (a[r] != x) { H.decrease(a[r--]); }
		if (l >= r)
			break;
		ans = max(ans, 2 * k + H.getMax());
		k++;
		l++; r--;
	}
	return ans;
}

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		memset(cnt, 0, A * 4);
		cin >> n;
		Loop(i, 0, n)
		{
			cin >> a[i]; a[i]--;
			cnt[a[i]]++;
		}
		int ans = 0;
		Loop(i, 0, A)
			ans = max(cnt[i], ans);
		Loop(i, 0, A)
		{
			if (cnt[i])
				ans = max(ans, Solve(i));
		}
		cout << ans << '\n';
	}
}