#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ri register int
const long double PI=3.141592653589793238462643383279;
const int M=998244353,N=500005;
int n,r,b,k,a[1000005],vis[1000005];
int x,i,m,t,u,j,mn,mnn;
long long ans;
priority_queue<int,vector<int>,greater<int> >q;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	for(m=0;(1<<m)!=n;++m);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		if(a[i]==-1)
			x=i;
	}
	u=1;
	for(i=n;i>x;--i)
	{
		q.push(a[i]);
		if(n-i+1==u)
		{
			ans+=q.top();
			q.pop();
			--m;
			u+=1<<m;
		}
	}
	cout<<ans;
}