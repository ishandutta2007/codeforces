#include<bits/stdc++.h>
using namespace std;
enum{N=500009};
int t[N],n,c[N];
void add(int x){for(;x<=n;x+=x&-x)++t[x];}
int sum(int x){int r=0;for(;x;x&=x-1)r+=t[x];return r;}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,i,x,y;
	long long ans;
	for(cin>>T;T--;cout<<'\n'){
		cin>>n,memset(t,0,n*4+4),memset(c,0,n*4+4),ans=0;
		for(i=1;i<=n;++i)cin>>x,y=sum(x),ans+=i-1-y,c[x]=i-1-2*(x-1),add(x);
		cout<<ans<<' ',sort(c+1,c+n+1);
		for(i=1;i<=n;++i)cout<<(ans-=c[n-i+1]+i-1)<<' ';
	}
	return 0;
}