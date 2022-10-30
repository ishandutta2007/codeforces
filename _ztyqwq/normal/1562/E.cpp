#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[5001];
const int MAXN = 5010;
struct LCP
{
	int t1[MAXN], t2[MAXN], c[MAXN]; //SA
	//ss[0]s[n-1],n,m,
	//s[n-1]s[i]0r[n-1]=0
	//sa,sa1~n
	bool cmp(int *r, int a, int b, int l)
	{
		return r[a] == r[b] && r[a + l] == r[b + l];
	}
	void da(int str[], int sa[], int rank1[], int height[], int n, int m)
	{ //nm128
		n++;
		int i, j, p, *x = t1, *y = t2;
		//s
		for (i = 0; i < m; i++)
			c[i] = 0;
		for (i = 0; i < n; i++)
			c[x[i] = str[i]]++;
		for (i = 1; i < m; i++)
			c[i] += c[i - 1];
		for (i = n - 1; i >= 0; i--)
			sa[--c[x[i]]] = i;
		for (j = 1; j <= n; j <<= 1)
		{
			p = 0;
			//sa
			for (i = n - j; i < n; i++)
				y[p++] = i; //j
			for (i = 0; i < n; i++)
				if (sa[i] >= j)
					y[p++] = sa[i] - j;
			//y
			//
			for (i = 0; i < m; i++)
				c[i] = 0;
			for (i = 0; i < n; i++)
				c[x[y[i]]]++;
			for (i = 1; i < m; i++)
				c[i] += c[i - 1];
			for (i = n - 1; i >= 0; i--)
				sa[--c[x[y[i]]]] = y[i];
			//saxx
			swap(x, y);
			p = 1;
			x[sa[0]] = 0;
			for (i = 1; i < n; i++)
				x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
			if (p >= n)
				break;
			m = p; //
		}
		int k = 0;
		n--;
		for (i = 0; i <= n; i++)
			rank1[sa[i]] = i;
		for (i = 0; i < n; i++)
		{
			if (k)
				k--;
			j = sa[rank1[i] - 1];
			while (str[i + k] == str[j + k])
				k++;
			height[rank1[i]] = k;
		}
	}
	int rank1[MAXN], height[MAXN];
	int RMQ[MAXN];
	int mm[MAXN];
	int best[20][MAXN];
	void initRMQ(int n)
	{ //daRMQLCP
		for (int i = 1; i <= n; i++)
			RMQ[i] = height[i];
		mm[0] = -1;
		for (int i = 1; i <= n; i++)
			mm[i] = ((i & (i - 1)) == 0) ? mm[i - 1] + 1 : mm[i - 1];
		for (int i = 1; i <= n; i++)
			best[0][i] = i;
		for (int i = 1; i <= mm[n]; i++)
			for (int j = 1; j + (1 << i) - 1 <= n; j++)
			{
				int a = best[i - 1][j];
				int b = best[i - 1][j + (1 << (i - 1))];
				if (RMQ[a] < RMQ[b])
					best[i][j] = a;
				else
					best[i][j] = b;
			}
	}
	int askRMQ(int a, int b)
	{
		int t;
		t = mm[b - a + 1];
		b -= (1 << t) - 1;
		a = best[t][a];
		b = best[t][b];
		return RMQ[a] < RMQ[b] ? a : b;
	}
	int lcp(int a, int b)
	{
		a = rank1[a];
		b = rank1[b];
		if (a > b)
			swap(a, b);
		return height[askRMQ(a + 1, b)];
	}
	int r[MAXN];  //
	int sa[MAXN]; //
	void Init(string s, int n)
	{
		for(int i = 1; i <= n; i++)
			r[i - 1] = s[i] - 'a' + 1;
		r[n] = 0;
		da(r, sa, rank1, height, n, 128);
		initRMQ(n);
	}
	inline int getLCP(int x, int y)
	{
		return lcp(x - 1, y - 1);
	}
};

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		string s;
		cin >> s;
		s = " " + s + " ";
		LCP lcp;
		lcp.Init(s, n);
		f[0] = 0;
		ll ans = 0;
		for(int i = 1; i <= n; i++)
		{
			f[i] = n - i + 1;
			for(int j = 1; j < i; j++)
			{
				int res = lcp.getLCP(i, j);
				if(s[j + res] < s[i + res])
					f[i] = max(f[i], f[j] + n - i + 1 - res);
			}
			ans = max(ans, f[i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}