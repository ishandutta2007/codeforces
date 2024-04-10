#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,q,cnt,rt[100100],bin[600100],tp;
#define lson t[x].ch[0]
#define rson t[x].ch[1]
typedef pair<int,int> pii;
struct Treap{int ch[2],rd,sz;pii val;}t[600100];
int newnode(pii val){int x=(tp?bin[tp--]:++cnt);lson=rson=0,t[x].val=val,t[x].rd=rand()*rand(),t[x].sz=1;return x;}
void pushup(int x){t[x].sz=t[lson].sz+t[rson].sz+1;}
void splitbyval(int x,pii k,int &u,int &v){
	if(!x){u=v=0;return;}
	if(t[x].val>=k)v=x,splitbyval(lson,k,u,lson);
	else u=x,splitbyval(rson,k,rson,v);
	pushup(x);
}
void splitbysz(int x,int k,int &u,int &v){
	if(!x){u=v=0;return;}
	if(t[lson].sz>=k)v=x,splitbysz(lson,k,u,lson);
	else u=x,splitbysz(rson,k-t[lson].sz-1,rson,v);
	pushup(x);
}
int merge(int x,int y){
	if(!x||!y)return x+y;
	if(t[x].rd<t[y].rd){t[x].ch[1]=merge(t[x].ch[1],y),pushup(x);return x;}
	else{t[y].ch[0]=merge(x,t[y].ch[0]),pushup(y);return y;}
}
void Insert(int&RT,pii val){
	int u,v;
	splitbyval(RT,val,u,v);
	RT=merge(merge(u,newnode(val)),v);
}
void Delete(int&RT,pii val){
	int u,v,w;
	splitbyval(RT,val,u,v);
	splitbysz(v,1,v,w);
	bin[++tp]=v;
	RT=merge(u,w);
}
ll Summary(int x){return x?Summary(lson)+t[x].val.first+Summary(rson):0;}
ll Tri(int&RT){
	int u,v;
	splitbysz(RT,3,u,v);
	ll ret=Summary(u);
	RT=merge(u,v);
	return ret;
}
pair<pii,pii>Two(int&RT){
	int a,b,c,d;
	splitbysz(RT,1,a,b);
	splitbysz(b,1,b,c);
	splitbysz(c,1,c,d);
	auto ret=make_pair(t[b].val,t[c].val);
	RT=merge(merge(a,b),merge(c,d));
	return ret;
}
int Count(int&RT,int k){
	int u,v;
	splitbyval(RT,make_pair(k,0),u,v);
	int ret=t[u].sz;
	RT=merge(u,v);
	return ret;
}
//void Iterate(int x){if(x)Iterate(lson),printf("%d ",t[x].val),Iterate(rson);} 
struct edge{
	int x,y,z;
	friend bool operator<(const edge&u,const edge&v){
		if(u.z!=v.z)return u.z<v.z;
		if(u.x!=v.x)return u.x<v.x;
		return u.y<v.y;
	}
	edge(int X,int Y,int Z){x=X,y=Y,z=Z;}
};
map<pair<int,int>,int>mp;
set<edge>s;
multiset<ll>ms;
void INSERT(){
	int x,y,z;scanf("%d%d%d",&x,&y,&z);
	if(x>y)swap(x,y);mp[make_pair(x,y)]=z;
	s.emplace(x,y,z);
	if(t[rt[x]].sz>=3)ms.erase(ms.find(Tri(rt[x])));
	if(t[rt[y]].sz>=3)ms.erase(ms.find(Tri(rt[y])));
	Insert(rt[x],make_pair(z,y)),Insert(rt[y],make_pair(z,x)),Insert(rt[0],make_pair(z,n+1));
	if(t[rt[x]].sz>=3)ms.insert(Tri(rt[x]));
	if(t[rt[y]].sz>=3)ms.insert(Tri(rt[y]));
}
void DELETE(){
	int x,y,z;
	scanf("%d%d",&x,&y);
	if(x>y)swap(x,y);z=mp[make_pair(x,y)],mp.erase(make_pair(x,y));
	s.erase(edge(x,y,z));
	if(t[rt[x]].sz>=3)ms.erase(ms.find(Tri(rt[x])));
	if(t[rt[y]].sz>=3)ms.erase(ms.find(Tri(rt[y])));
	Delete(rt[x],make_pair(z,y)),Delete(rt[y],make_pair(z,x)),Delete(rt[0],make_pair(z,n+1));
	if(t[rt[x]].sz>=3)ms.insert(Tri(rt[x]));
	if(t[rt[y]].sz>=3)ms.insert(Tri(rt[y]));
}
bool che(int x,int y,int z){return Count(rt[x],z)+Count(rt[y],z)-1>=Count(rt[0],z);}
ll calc(){
//	for(int i=0;i<=n;i++)printf("%d:",i),Iterate(rt[i]),puts("");
	ll ret=0x3f3f3f3f3f3f3f3f;
	if(!ms.empty())ret=min(ret,*ms.begin());
//	printf("QAQ:%lld\n",ret);
	int x=s.begin()->x,y=s.begin()->y,z=s.begin()->z;
//	printf("QWQ:%d,%d\n",x,y);
	if(t[rt[x]].sz>=2&&t[rt[y]].sz>=2){
		auto X=Two(rt[x]),Y=Two(rt[y]);
		if(X.first.second&&Y.first.second&&X.first.second!=Y.first.second)ret=min(ret,0ll+X.first.first+Y.first.first);
		if(X.first.second&&Y.second.second&&X.first.second!=Y.second.second)ret=min(ret,0ll+X.first.first+Y.second.first);
		if(X.second.second&&Y.first.second&&X.second.second!=Y.first.second)ret=min(ret,0ll+X.second.first+Y.first.first);
	}
	int l=z,r=1e9+1;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(che(x,y,mid))l=mid;
		else r=mid-1;
	}
	if(!che(x,y,l+1))ret=min(ret,0ll+z+l);
	return ret;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)INSERT();
	printf("%lld\n",calc());
	scanf("%d",&q);
	for(int i=1,tp;i<=q;i++)scanf("%d",&tp),tp?INSERT():DELETE(),printf("%lld\n",calc());
	return 0;
}
/*
6 6
1 3 6
4 3 1
1 4 1
2 6 4
2 4 2
5 4 3
3
1 2 5 2
0 1 4
0 3 4
*/