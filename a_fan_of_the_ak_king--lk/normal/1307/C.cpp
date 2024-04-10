#include<bits/stdc++.h>
using namespace std;
const int N=100005,M=1000000007;
typedef long double lb;
int n,d,t,i,g[66],j,k;
long long ans,s1,s2,f[26][26];
char c[100005];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%s",c+1);
	for(i=1;c[i];++i)
	{
		for(j=0;j<26;++j)
			f[j][c[i]-'a']+=g[j];
		++g[c[i]-'a'];
	}
	for(j=0;j<26;++j)
	{
		for(k=0;k<26;++k)
			ans=max(ans,f[j][k]);
		ans=max(ans,g[j]*1ll);
	}
	cout<<ans;
}