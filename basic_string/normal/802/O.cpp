#include<bits/stdc++.h>
using namespace std;
enum{N=500009};
int a[N],b[N],n,k;
long long ans;
struct P{
	int x;
	bool b;
	bool operator<(P a)const{return x>a.x||(x==a.x&&b);}
};
int get(int x){
	priority_queue<P>q;
	ans=0;
	int c=0;
	for(int i=1;i<=n;++i){
		q.push({a[i],1});
		if(q.top().x-x+b[i]<0){
			ans+=q.top().x-x+b[i],c+=q.top().b,q.pop();
			q.push({x-b[i],0});
		}
	}
	return c;
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int i,l,r,m;
	for(cin>>n>>k,i=1;i<=n;++i)cin>>a[i];
	for(i=1;i<=n;++i)cin>>b[i];
	l=0,r=2e9+9;
	while(l<=r){
		m=(l+0ll+r)>>1;
		if(get(m)>k)r=m-1;else l=m+1;
	}
	get(r),cout<<ans+k*1ll*r;
}