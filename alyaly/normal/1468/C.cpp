#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a),i##z=(b);i<=i##z;i++)
#define ROF(i,a,b) for(int i=(a),i##z=(b);i<=i##z;i--)
#define temT template<typename T>
using namespace std;
typedef long long ll;
const int N=int(5e5)+10,inf=int(1e9)+7;

int Q; int val[N*4],ct;

#define RT 1,1,Q
#define mid (l+r>>1)
#define LS p<<1,l,mid
#define RS p<<1|1,mid+1,r

void mt(int p){
	val[p]=max(val[p<<1],val[p<<1|1]);
}

void build(int p,int l,int r){
	if(l==r) return val[p]=-inf,void();
	build(LS); build(RS); mt(p);
}

void ins(int p,int l,int r,int ep,int v){
	if(l==r) return val[p]=v,void();
	if(ep<=mid)	ins(LS,ep,v);
	else		ins(RS,ep,v); mt(p);
}

int ask1(int p,int l,int r){
	if(l==r) return l;
	if(val[p<<1]!=-inf)
		return ask1(LS);
	else
		return ask1(RS);
}

int ask2(int p,int l,int r){
	if(l==r) return l;
	if(val[p<<1] >= val[p<<1|1])
		return ask2(LS);
	else
		return ask2(RS);
}

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>Q; build(RT);
	
	for(int op,x,t,i=1;i<=Q;i++){
		cin>>op;
		if(op==1)
			cin>>x,ct++,ins(RT,ct,x);
		if(op==2)
			cout<<(t=ask1(RT))<<" ";
		if(op==3)
			cout<<(t=ask2(RT))<<" ";
		if(op!=1) ins(RT,t,-inf);
	}
	
	return 0;
}