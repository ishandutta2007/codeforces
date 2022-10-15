#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAXL = 200007;

char a[MAXL], b[MAXL];
long double f[2][MAXL], g[2][MAXL];
long double s[2];
int n;

vector < pair < pair <int, int>, int > > v;


template <typename T> T sqr(T x) { return x * x; }

void modify(long double *f, int x, long double d)
{
	for (int i = x; i <= n; i = (i | (i - 1)) + 1)
		f[i] += d;
}

long double find(long double *f, int x)
{
	long double res = 0;
	for (int i = x; 0 < i; i = i & (i - 1))
		res += f[i];
	return res; 
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	
	scanf("%d\n", &n);
	gets(a);
	gets(b);

	
	long double res = 0, cnt = 0;
	for (int C = 'A'; C <= 'Z'; C++)
	{
		v.clear();
		for (int i = 0; i < n; i++)
			if (a[i] == C)
				v.push_back(make_pair(make_pair(i + 1, n - i), 0));
		
		for (int i = 0; i < n; i++)
			if (b[i] == C)
				v.push_back(make_pair(make_pair(i + 1, n - i), 1));
				
		sort(v.begin(), v.end());
		
		memset(f, 0, sizeof(f));
		memset(g, 0, sizeof(g));
		memset(s, 0, sizeof(s));
		
		for (int i = 0; i < (int)v.size(); i++)
		{
			int t = v[i].second;
			int x = v[i].first.first;
			int y = v[i].first.second;

			//printf("%d %d %d\n", x, y, t);
			
			t = 1 - t;
			//cout << find(f[t], y) << endl;
			res += find(f[t], y);
			res += (s[t] - find(g[t], y)) * y;
			t = 1 - t;
			
			s[t] += x;
			modify(f[t], y, x * (long double)y);
			modify(g[t], y, x);
		}
	}
	//cout << res << endl;
	
	for (int i = 0; i < n; i++)
		cnt += sqr((long double)(n - i));
	//cout << cnt << endl;

	printf("%.10lf\n", (double)(res / cnt));
	return 0;
}