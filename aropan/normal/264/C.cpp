#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }

const long long INF = (long long)1e+18;

const int MAXN = 200005; 

int n, m;
long long f[MAXN];
long long v[MAXN];
int c[MAXN];
int fs, sc;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%I64lld", &v[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &c[i]);

	while (m--)
	{
		long long A, B;
		long long ans = 0;
		cin >> A >> B;
		
		for (int i = 1; i <= n; i++)
			f[i] = -INF;
		f[0] = 0;
		fs = sc = 0;
		for (int i = 0; i < n; i++)
		{
			f[c[i]] = 
				max(f[c[i]], 
					max(
						f[c[i]] + v[i] * A,
						(fs == c[i]? f[sc] : f[fs]) + v[i] * B
					)
				);
			if (c[i] == fs || c[i] == sc)
			{
				if (f[fs] < f[sc])
					swap(fs, sc);
			}
			else
			{
				if (f[c[i]] > f[fs])
				{
					sc = fs;
					fs = c[i];
				}
				else
				if (f[c[i]] > f[sc])
				{
					sc = c[i];
				}
			}
			ans = max(ans, f[c[i]]);
		}
		cout << ans << endl;
	}

	return 0;
}