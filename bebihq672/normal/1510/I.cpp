#include<bits/stdc++.h>
using namespace std;

char s[1010];

int a[1010];
int per[1010];

double f[1010];

bool cmp(const int &x, const int &y)
{
	return a[x] > a[y];
}

int main()
{
	mt19937 rnd; 
	int n, m;
	scanf("%d%d", &n, &m);
	
	for(int i = 1; i <= n; i++)
		per[i] = i;
	
	for(int t = 1; t <= m; t++)
	{
		scanf("%s", s + 1);
		__float128 tmp = rnd() / __float128(2147483648ll * 2);
		
		__float128 sum = 0;
		
		for(int i = 1; i <= n; i++)
		{
			f[i] = 1.0 * t / (a[i] + 0.1);
			f[i] = exp(f[i] * 5);
		}
		
		sort(per + 1, per + n + 1, cmp);
		
		for(int i = 1; i <= n; i++)
			sum += f[per[i]];
		for(int i = 1; i <= n; i++)
			f[i] /= sum;
		
		
		int res = 0;
		for(int i = n; i >= 1; i--)
		if(tmp > f[per[i]])
			tmp -= f[per[i]];
		else
		{
			res = s[per[i]] - '0';
			break;
		}
		printf("%d\n", (int)res);
		fflush(stdout);
		int ans;
		scanf("%d", &ans);
		for(int i = 1; i <= n; i++)
		if(s[i] - '0' != ans)
			a[i]++;
	}
	
	
	return 0;
}