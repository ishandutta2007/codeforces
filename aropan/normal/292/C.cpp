#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }

bool f[10];
int d[10];
int x[256];
vector <int> v;
int n;
int k, r, R;
vector <int> a;
char s[20];

vector < vector <int> > ans;

void rec(int m)
{
	if ((4 - m) * 3 < (n - k) || (n - k) < (4 - m))
		return;
		
	if (m == 4)
	{
		ans.push_back(a);
		return;
	}
	
	for (int i = 0; i < (int)v.size(); i++)
	{
		char c[4];
		sprintf(c, "%d", v[i]);
		
		bool flg = true;
		int j;
		for (j = 0; c[j]; j++)
		{
			s[k] = c[j];
			r += d[c[j] - '0'] == 0;
			d[c[j] - '0'] += 1;
			flg &= (k * 2 < n || s[n - k - 1] == s[k]);
			k++;
		}
		flg &= max((n + 1) / 2 - k, 0) + r >= R;
		if (flg)
		{
			a[m] = v[i];
			rec(m + 1);
		}
		for (j = 0; c[j]; j++)
		{
			d[c[j] - '0'] -= 1;
			r -= d[c[j] - '0'] == 0;
			k--;
		}
	}
	
}
	
int main()
{
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	
	scanf("%d", &n);
	R = n;
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		f[x] = true;
	}
	
	x[0] = true;
	for (int i = 1; i < 256; i++)
	{
		x[i] = x[i / 10] && f[i % 10];
	}
	x[0] = f[0];
	
	for (int i = 0; i < 256; i++)
		if (x[i])
			v.push_back(i);
	
	a.resize(4);
	for (n = 4; n <= 12; n++)
	{
		k = r = 0;
		memset(d, 0, sizeof(d));
		rec(0);
	}
	
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < (int)ans.size(); i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (j)
				printf(".");
			printf("%d", ans[i][j]);
		}
		printf("\n");
	}
	
	fprintf(stderr, "Time execute: %.3lfs\n", clock() / (double)CLOCKS_PER_SEC);
	return 0;
}