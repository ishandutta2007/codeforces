#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  998244353
using namespace std;
struct treap{
    int size,val,key;
    int id,ad;
    treap* ch[2];
};
treap *empty,*root;
void init(treap *t,int x){t->val=x,t->key=rand(),t->size=1,t->ch[0]=t->ch[1]=empty,t->ad=0;}
void ps(treap *t){
	if(t->ad==0) return;
	if(t->ch[0]!=empty)t->ch[0]->ad+=t->ad;
	if(t->ch[1]!=empty)t->ch[1]->ad+=t->ad;
	t->val+=t->ad;
	t->ad=0;
}
treap *merge(treap *x,treap *y){
    if(x==empty) return y;
    if(y==empty) return x;
    ps(x);
    ps(y);
    if(x->key<y->key){x->size+=y->size,x->ch[1]=merge(x->ch[1],y);return x;}
    y->size+=x->size,y->ch[0]=merge(x,y->ch[0]);return y;
}
pair<treap*,treap*> split(treap *t,int k){
    if(t==empty) return mp(t,t);
    pair<treap*,treap*> ret;
    if(t->ch[0]->size>=k)ret=split(t->ch[0],k),t->ch[0]=ret.second,t->size-=k,ret.second=t;
    else ret=split(t->ch[1],k-t->ch[0]->size-1),t->ch[1]=ret.first,t->size=k,ret.first=t;
    return ret;
}
int rk(treap *t,int x){
    if(t==empty) return 0;
    ps(t);
    if(t->val>=x) return rk(t->ch[0],x);
    return rk(t->ch[1],x)+t->ch[0]->size+1;
}
int get(treap *t,int k){
	ps(t);
    if(t->ch[0]->size>=k) return get(t->ch[0],k);
    if(t->ch[0]->size+1==k) return t->val;
    return get(t->ch[1],k-t->ch[0]->size-1);
}
int I;
void ins(int x){
    treap *v=new treap;
    init(v,x);
    v->id=I;
    pair<treap*,treap*> p=split(root,rk(root,x));
    if(p.second!=empty)p.second->ad+=1;
    root=merge(merge(p.first,v),p.second);
}
void del(int k){
    pair<treap*,treap*> p=split(root,k-1),q=split(p.second,1);
    root=merge(p.first,q.second);
}
ll jc[400005],njc[400005];
ll fp(ll x,int k=orz-2){
	ll a=1;
	while(k){
		if(k&1)(a*=x)%=orz;
		k>>=1,(x*=x)%=orz;
	}
	return a;
}
ll C(int n,int k){return jc[n]*njc[k]%orz*njc[n-k]%orz;}
int T,n,m,k;
pair<int,int> p[200005];
void dfs(treap *t){
	if(t==empty) return;
	ps(t);
	dfs(t->ch[0]);
	p[++k]=mp(t->val,t->id);
	dfs(t->ch[1]);
}
int main(){
	
    empty=new treap;
    empty->size=0,empty->val=0,empty->key=0,empty->ch[0]=empty->ch[1]=empty;
	jc[0]=1;
	for(int i=1;i<=400000;++i)jc[i]=jc[i-1]*i%orz;
	njc[400000]=fp(jc[400000]);
	for(int i=400000;i;--i)njc[i-1]=njc[i]*i%orz;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		root=new treap;
    	init(root,orz);
    	for(int i=1;i<=m;++i){
    		int x,y;
    		scanf("%d%d",&x,&y);
    		I=x;
			ins(y);
		}
		k=0;
		dfs(root);
		int o=0;
		for(int i=1;i<=k;++i){
			if(p[i].first>n) continue;
			if(i<k&&p[i].first+1==p[i+1].first){
				if(p[i].second>p[i+1].second)++o;
			}
			else if(p[i].first!=n)++o;
		}
		printf("%I64d\n",C(n*2-o-1,n));
	}
    return 0;
}