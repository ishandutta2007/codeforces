#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
#define inf 0x3f3f3f3f
int d[510][504];
int a[510];

int
main(void)
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf("%d", &d[i][j]);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[n-i]);
	
	vector<long long> retv;
	for(int i = 0; i < n; i++)
	{
		long long ans = 0;
		for(int j = 1; j <= n; j++)
			for(int k = 1; k <= n; k++)
				d[j][k] = min(d[j][k], d[j][a[i]] + d[a[i]][k]);
		for(int j = 0; j <= i; j++)
			for(int k = 0; k <= i; k++)
			 ans += d[a[j]][a[k]];
		retv.push_back(ans);
	}
	for(int i = n-1; i >= 0; i--)
		cout << retv[i] << ' ';
	cout << '\n';
	return 0;
}