#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
int n,K,i,j,g[505],a[505],c[505];
int main()
{
	cin>>n>>K;
	for(i=1;i<=K+1;++i)
	{
		cout<<'?';
		for(j=1;j<=K+1;++j)
			if(i!=j)
				cout<<' '<<j;
		cout<<endl;
		cout.flush();
		cin>>g[i];
		cin>>a[g[i]];
		c[g[i]]++;
	}
	for(i=1,j=0;i<=K+1;++i)
		if(c[i]>c[j])
			j=i;
	if(a[g[j]]<a[j])
		cout<<'!'<<' '<<c[j];
	else
		cout<<'!'<<' '<<K-c[j]+1;
	return 0;
}