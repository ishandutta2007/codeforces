#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,ans,p[200005];
map <int,int> mp;
struct node{
	int x,y;
}c[200005];
bool cmp(node a,node b){
	return a.y<b.y||(a.y==b.y&&a.x<b.x);
}
ll v[200005],vv[200005];
void add(ll x,ll y){
	while(x<=n)v[x]+=y,vv[x]++,x+=x&-x;
}
ll query(ll x){
	ll ans=0;
	while(x)ans+=v[x],x-=x&-x;
	return ans;
}
int query2(int x){
	int ans=0;
	while(x)ans+=vv[x],x-=x&-x;
	return ans;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>c[i].x,p[i]=c[i].x;
	for(int i=1;i<=n;i++)cin>>c[i].y;
	sort(c+1,c+n+1,cmp);
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++)mp[p[i]]=i;
	for(int i=1;i<=n;i++){
		ans+=1ll*c[i].x*query2(mp[c[i].x])-query(mp[c[i].x]);
		add(mp[c[i].x],c[i].x);
	}
	cout<<ans<<endl;
	return 0;
}