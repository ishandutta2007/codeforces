#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

#define maxn 100100

int a[maxn], b[maxn], c[maxn];

int main()
{
	int n,m,k,x;
	long long res = 0;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < m; i++) scanf("%d%d%d", &a[i], &b[i], &c[i]);
	for(int i = 0; i < k; i++)
	{
		scanf("%d", &x);
		for(int j = 0; j < m; j++) if(a[j] <= x && x <= b[j])
			res += c[j] + x - a[j];
	}
	cout << res << endl;
}