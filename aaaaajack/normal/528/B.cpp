#include<cstdlib>
#include<cstdio>
#include<algorithm>
#define N 200100
using namespace std;
struct vertex{
	int x;
	int w;
	vertex(){}
	vertex(int _x,int _w):x(_x),w(_w){}
	bool operator<(vertex rhs)const{return x<rhs.x;}
}v[N];
struct treap{
	int key;
	int pri;
	int val;
	int mx;
	treap *l,*r;
	treap(){}
	treap(int _key,int _val):key(_key),val(_val),pri(rand()<<16|rand()),mx(_val),l(NULL),r(NULL){}
};
int mxval(treap *x){
	return x?x->mx:0;
}
void pull(treap *x){
	x->mx=max(x->val,max(mxval(x->l),mxval(x->r)));
}
treap *merge(treap *a,treap *b){
	if(!a||!b) return a?a:b;
	if(a->pri>b->pri){
		a->r=merge(a->r,b);
		pull(a);
		return a;
	}
	else{
		b->l=merge(a,b->l);
		pull(b);
		return b;
	}	
}
void split(treap *t,int k,treap *&a, treap *&b){
	if(!t){
		a=b=NULL;
		return;
	}
	if(k<t->key){
		b=t;
		split(t->l,k,a,b->l);
		pull(b);
	}
	else{
		a=t;
		split(t->r,k,a->r,b);
		pull(a);
	}
}
int main(){
	int n,i,now;
	treap *t=NULL,*a,*b;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&v[i].x,&v[i].w);
	}
	sort(v,v+n);
	for(i=0;i<n;i++){
		split(t,v[i].x-v[i].w,a,b);
		now=mxval(a)+1;
		t=merge(a,b);
		split(t,v[i].x+v[i].w,a,b);
		t=merge(a,merge(new treap(v[i].x+v[i].w,now),b));
	}
	printf("%d\n",mxval(t));
	return 0;
}