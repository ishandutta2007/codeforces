#include<bits/stdc++.h>
using namespace std;
const int M=1000000007,P=998244353;
const int N=200005,E=262144;
#define inf 2147483647
int n,i,j,s,ans;
char c[1000005];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	scanf("%s",c+1);
	for(i=1;c[i];++i)
	{
		if(c[i]==')')
			--s;
		if(s<0)
			++ans;
		if(c[i]=='(')
			++s;
	}
	if(s!=0)
		ans=-1;
	cout<<ans;
}