#include <bits/stdc++.h>
using namespace std;
const int N=4e5+5;
map <pair<int,int>,bool> mp;
int n,m,k,val[N<<2],tg[N<<2];
void push(int x){
	if(!tg[x])return;
	tg[x<<1]+=tg[x],tg[x<<1|1]+=tg[x];
	val[x<<1]+=tg[x],val[x<<1|1]+=tg[x],tg[x]=0;
}
void build(int l,int r,int x){
	if(l==r){val[x]=l-1; return;}
	int m=l+r>>1;
	build(l,m,x<<1),build(m+1,r,x<<1|1);
	val[x]=max(val[x<<1],val[x<<1|1]);
}
void modify(int l,int r,int qr,int x,int v){
	if(r<=qr){val[x]+=v,tg[x]+=v; return;}
	int m=l+r>>1; push(x);
	modify(l,m,qr,x<<1,v);
	if(m<qr)modify(m+1,r,qr,x<<1|1,v);
	val[x]=max(val[x<<1],val[x<<1|1]);
}
int query(int l,int r,int qr,int x){
	if(r<=qr)return val[x]; push(x);
	int m=l+r>>1,ans=query(l,m,qr,x<<1);
	if(m<qr)ans=max(ans,query(m+1,r,qr,x<<1|1));
	return ans;
}
multiset <int> s;
int main(){
	cin>>n>>k>>m,n*=2; build(1,n,1);
	for(int i=1,x,y,pos;i<=m;i++){
		cin>>x>>y; pos=y+abs(x-k);
		if(mp[{x,y}])modify(1,n,pos,1,-1),s.erase(s.find(pos));
		else modify(1,n,pos,1,1),s.insert(pos);
		mp[{x,y}]^=1,cout<<(s.size()==0?0:max(0,query(1,n,*--s.end(),1)-n/2))<<endl;
	}
	return 0;
}