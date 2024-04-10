#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N=5e4+5;
const int p=1e9+7;
const int B=30;

int n,m,a[N];
int node,R[N],ls[N<<5],rs[N<<5],val[N<<5],c[N<<5][B];
void modify(int pre,int &x,int p,int b){
	val[x=++node]=val[pre]+1,ls[x]=ls[pre],rs[x]=rs[pre];
	for(int i=0;i<B;i++)c[x][i]=c[pre][i]+(p>>i&1);
	if(b==0)return;
	if((p>>b-1)&1)modify(rs[pre],rs[x],p,b-1);
	else modify(ls[pre],ls[x],p,b-1);
}
ll query(int p,int k,int b,int x,int y){
	if(b==0)return val[y]-val[x];
	int bit=(p>>b-1)&1,t=(k>>b-1)&1;
	if(bit){
		if(t)return query(p,k,b-1,ls[x],ls[y]);
		else return val[ls[y]]-val[ls[x]]+query(p,k,b-1,rs[x],rs[y]);
	} 
	else{
		if(t)return query(p,k,b-1,rs[x],rs[y]);
		else return val[rs[y]]-val[rs[x]]+query(p,k,b-1,ls[x],ls[y]);
	}
}

ll cal(int x,int y,int p){
	ll ans=0;
	for(ll i=0;i<B;i++)
		if((p>>i)&1)ans+=(ll)(val[y]-val[x]-c[y][i]+c[x][i])<<i;
		else ans+=(ll)(c[y][i]-c[x][i])<<i;
	return ans;
}
ll sum(int p,int k,int b,int x,int y){
	if(b==0)return cal(x,y,p);
	int bt=(p>>b-1)&1,t=(k>>b-1)&1;
	if(bt){
		if(t)return sum(p,k,b-1,ls[x],ls[y]);
		else return cal(ls[x],ls[y],p)+sum(p,k,b-1,rs[x],rs[y]);
	}
	else{
		if(t)return sum(p,k,b-1,rs[x],rs[y]);
		else return cal(rs[x],rs[y],p)+sum(p,k,b-1,ls[x],ls[y]);
	}
}

int main(){
	cin>>n>>m;
	if(m==0)return cout<<0<<endl,0;
	for(int i=1;i<=n;i++)cin>>a[i],modify(R[i-1],R[i],a[i],B);
	ll l=0,r=1<<B,ans=0,cnt=0; // remember
	while(l<r){
		ll mid=(l+r>>1)+1,cnt=0;
		for(int i=1;i<=n;i++)cnt=cnt+query(a[i],mid,B,R[i],R[n]);
		cnt>=m?l=mid:r=mid-1;
	}
	for(int i=1;i<n;i++)cnt=cnt+query(a[i],l,B,R[i],R[n]);
	for(int i=1;i<n;i++)ans+=sum(a[i],l,B,R[i],R[n]);
	cout<<(ans-(cnt-m)*l%p+p)%p<<endl;
	return 0;
}