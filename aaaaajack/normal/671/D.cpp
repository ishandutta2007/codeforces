#include<bits/stdc++.h>
#define N 300100
using namespace std;
struct mh{
	mh *l,*r;
	int u;
	int c,a;
	mh(){}
	mh(int _u,int _c):u(_u),c(_c),a(0),l(0),r(0){}
	void push(){
		if(l) l->a+=a;
		if(r) r->a+=a;
		c+=a;
		a=0;
	}
};
int dep[N],cov[N];
long long ans;
bool gg;
mh *to[N];
vector<int> g[N],c[N],t[N];
mh* meld(mh *a,mh *b){
	if(!a||!b) return a?a:b;
	if(a->c+a->a > b->c+b->a) swap(a,b);
	a->push();
	if(rand()&1) a->r=meld(a->r,b);
	else a->l=meld(a->l,b);
	return a;
}
mh* lazy_min(mh *t,int u){
	mh *res;
	if(t&&dep[t->u]>=dep[u]){
		t->push();
		res=meld(lazy_min(t->l,u),lazy_min(t->r,u));
		delete t;
	}
	else res=t;
	return res;
}
void DFS(int u,int d){
	dep[u]=d;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(!dep[v]){
			DFS(v,d+1);
			cov[u]+=cov[v];
			to[u]=meld(to[u],to[v]);
		}
	}
	for(int i=0;i<t[u].size();i++){
		to[u]=meld(to[u],new mh(t[u][i],c[u][i]));
	}
	if(u>1&&!cov[u]){
		to[u]=lazy_min(to[u],u);
		if(!to[u]){
			gg=true;
		}
		else{
			to[u]->push();
			ans+=to[u]->c;
			cov[u]++;
			cov[to[u]->u]--;
			mh *tmp=to[u];
			to[u]=meld(to[u]->l,to[u]->r);
			if(to[u]) to[u]->a-=tmp->c;
			delete tmp;
		}
	}
}
int main(){
	int n,m,x,y,z;
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&x,&y,&z);
		t[x].push_back(y);
		c[x].push_back(z);
	}
	DFS(1,1);
	if(gg) puts("-1");
	else printf("%I64d\n",ans);
	return 0;
}