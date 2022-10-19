#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

#define inf (999999999999LL)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define eps 1e-8
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 100100
#define max3(a,b,c) max(max(a,b),c)

using namespace std;

struct node {

	node *l,*r;
	int val, esq, dir, all;

	void update(int,int,int,node*,int,int);
	void query(int,int,int,int);

	void clear(){
		val = esq = dir = all = 0;
		l = r = 0;
	}

};

inline void join(node*l,node*r,node*t){

	t->val = max3(l->val,r->val,l->dir+r->esq);
	t->dir = r->dir;
	if(r->all) t->dir = r->val + l->dir;
	t->esq = l->esq;
	if(l->all) t->esq = l->val + r->esq;
	if(r->all && l->all) t->all = 1;
	else t->all = 0;

}

void node :: update(int init,int fim,int pos,node* back,int f,int v){

	debug("upd %d-%d (%d)\n",init,fim,pos);
	if(init > pos || fim < pos) return;

	if(init == fim){
		val = esq = dir = all = v;
		return;
	}

	int mid = (init+fim)/2;

	if(f){
		if(l == 0)
			l = (node*) malloc(sizeof(node)), l -> clear();
		if(r == 0)
			r = (node*) malloc(sizeof(node)), r -> clear();
	}


	if(pos <= mid){
		if(f == 0 && l == 0)
			l = (node*) malloc(sizeof(node)), l -> clear();
		l->update(init,mid,pos,back->l,f,v);
		if(f == 0)
			r = back->r;
	}
	else {
		if(f == 0 && r == 0)
			r = (node*) malloc(sizeof(node)), r -> clear();
		r->update(mid+1,fim,pos,back->r,f,v);
		if(f == 0)
			l = back->l;
	}

	
	join(l,r,this);

}

node* ans;
node* root[maxn];
node* aux;

void node :: query(int init,int fim,int a,int b){

	if(init > b || fim < a) return;

	if(init >= a && fim <= b){
		aux = (node*)malloc(sizeof(node));
		aux->clear();
		join(ans,this,aux);
		free(ans);
		ans = aux;
		return;
	}

	int mid = (init+fim)/2;
	l->query(init,mid,a,b);
	r->query(mid+1,fim,a,b);

}

main(){

		debug("%d\n",sizeof(node));
		
		int n;
		scanf("%d",&n);

		vector<pii> u;

		for(int i=0;i<n;i++){
			int a;
			scanf("%d",&a);
			u.pb(pii(a,i));
		}

		for(int i=0;i<n;i++){
			root[i] = (node*) malloc(sizeof(node));
			root[i] -> clear();
		}

		for(int i=0;i<n;i++){
			debug("i=%d\n",i);
			root[0]->update(0,n-1,i,root[0],1,0);
			debug("build %d ok\n",i);
		}

		debug("build ok\n");
		sort(u.begin(), u.end());
		reverse(u.begin(), u.end());

		for(int i=0;i<n;i++){
			root[i]->update(0,n-1,u[i].second,i?root[i-1]:root[i],i?0:1,1);
			debug("%d ok\n",i);
		}

		int q;
		scanf("%d",&q);

		ans = (node*) malloc(sizeof(node));

		while(q--){

			int a,b,w;
			scanf("%d%d%d",&a,&b,&w), a--, b--;

			int low = 0, up = n-1;

			while(up-low){
				int mid = (up+low)/2;
				ans->clear();
				root[mid]->query(0,n-1,a,b);
				if(ans->val >= w)
					up = mid;
				else
					low = mid+1;
			}

			printf("%d\n",u[low].first);

		}

}