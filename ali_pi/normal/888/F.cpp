#include <bits/stdc++.h>

using namespace std;
const int p=1000000007;

int f[600][600],g[600][600],h[600][600];
int i,j,k,n;

int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			cin>>g[i][j];
	for (i=1;i<=n;i++)
		f[i][i]=1;
	for (i=1;i<n;i++)
		for (j=1;i+j<=n;j++)
		{
			for (k=j;k<=i+j;k++)
				f[j][i+j]=(f[j][i+j]+1LL*f[j][k]*h[k][i+j])%p;
			if (g[j][i+j])
				for (k=j;k<i+j;k++)
					h[j][i+j]=(h[j][i+j]+1LL*f[j][k]*f[k+1][i+j])%p;
			f[j][i+j]=(f[j][i+j]+h[j][i+j])%p;
		}
	cout<<f[1][n];
}