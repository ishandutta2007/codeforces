#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,i,j,k,c[50][50],f[1100000],w[1100000];
char s[100005];
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(i=1;i<n;++i)
	{
		c[s[i]-'a'][s[i+1]-'a']++;
		c[s[i+1]-'a'][s[i]-'a']++;
	}
	w[0]=0;
	for(i=1;i<(1<<m);++i)
	{
		for(j=0;j<m;++j)
			if(i>>j&1)
				break;
		w[i]=w[i^(1<<j)];
		for(k=0;k<m;++k)
			if(k!=j)
			{
				if(i>>k&1)
					w[i]-=c[k][j];
				else
					w[i]+=c[k][j];
			}
	}
	for(j=1;j<(1<<m);++j)
		f[j]=1<<30;
	f[0]=0;
	for(j=0;j<(1<<m);++j)
		if(f[j]<(1<<30))
		{
			for(k=0;k<m;++k)
				if(!(j>>k&1))
					f[j|(1<<k)]=min(f[j|(1<<k)],f[j]+w[j|(1<<k)]);
		}
	printf("%d",f[(1<<m)-1]);
	return 0;
}