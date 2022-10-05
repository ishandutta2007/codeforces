#include<bits/stdc++.h>
using namespace std;
const int N=757;
#define ll long long
priority_queue<ll>q;
ll a[N],b[N];
int main(){
	int n,m,t=0,i;
	ll w;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%lld",a+i);
	for(i=n;i;--i){
		while(!q.empty()&&a[i]>=0)a[i]+=q.top(),q.pop();
		if(a[i]<0)q.push(a[i]);
	}
	while(!q.empty())++t,b[t]=b[t-1]-q.top(),q.pop();
	while(m--)scanf("%lld",&w),printf("%d\n",t-(upper_bound(b,b+t+1,w)-b-1));
	return 0;
}