#include<bits/stdc++.h>
using namespace std;
int n,f[100005][11],i,j,k;
char c[100005];
long long ans;
int main()
{
	scanf("%s",c+1);
	n=strlen(c+1);
	for(i=1;i<=n;++i)
	{
		for(j=0;j<=10;++j)
			if(j>c[i]-'0')
				f[i][(j*(j-1)/2+c[i]-'0'+10)%11]+=f[i-1][j];
		if(c[i]!='0')
			++f[i][c[i]-'0'];
		for(j=0;j<=10;++j)
			ans+=f[i][j];
	}
	cout<<ans<<endl;
}