#include<cstdio>
#include<cstdlib>
#include<utility>
#include<algorithm>
#define N 100100
using namespace std;
struct treap{
	int pri;
	long long add;
	int acnt;
	long long sum;
	int cnt;
	int sz;
	bool operator<(treap rhs)const{return cnt*rhs.sum<sum*rhs.cnt;}
	treap *l,*r;
	treap(int _cnt,long long _sum):pri(rand()),l(NULL),r(NULL),add(0),acnt(0),sum(_sum),cnt(_cnt),sz(1){}
};
inline int size(treap *t){
	return t?t->sz:0;
}
void push(treap *t){
	if(t->l){
		t->l->sum+=t->add;
		t->l->add+=t->add;
		t->l->cnt+=t->acnt;
		t->l->acnt+=t->acnt;
	}
	if(t->r){
		t->r->sum+=t->add;
		t->r->add+=t->add;
		t->r->cnt+=t->acnt;
		t->r->acnt+=t->acnt;
	}
	t->add=t->acnt=0;
}
void pull(treap *t){
	t->sz=size(t->l)+size(t->r)+1;
}
treap* merge(treap* a,treap* b){
	if(!a||!b) return a?a:b;
	if(a->pri>b->pri){
		push(a);
		a->r=merge(a->r,b);
		pull(a);
		return a;
	}
	else{
		push(b);
		b->l=merge(a,b->l);
		pull(b);
		return b;
	}
}
void split(treap *t,int k,treap *&a,treap *&b){
	if(!t){
		a=b=NULL;
		return;
	}
	push(t);
	if(size(t->l)+1<=k){
		a=t;
		split(t->r,k-size(t->l)-1,a->r,b);
		pull(a);
	}
	else{
		b=t;
		split(b->l,k,a,b->l);
		pull(b);
	}
}
int count(treap *t,int v){
	if(!t) return 0;
	push(t);
	if(1LL*v*t->cnt<=t->sum) return size(t->l)+1+count(t->r,v);
	else return count(t->l,v);
}
pair<long long,long long> solve(treap *t){
	if(!t) return make_pair(0LL,0LL);
	push(t);
	pair<long long,long long> lans=solve(t->l);
	pair<long long,long long> rans=solve(t->r);
	long long tsum=lans.first+rans.first+t->sum;
	long long tmx=max(max(lans.second,lans.first+t->sum),lans.first+t->sum+rans.second);
	return make_pair(tsum,tmx);
}
int main(){
	int n,k,x;
	treap *t=NULL,*a,*b;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		k=count(t,x);
		split(t,k,a,b);
		if(b){
			b->add+=x;
			b->acnt++;
			b->sum+=x;
			b->cnt++;
		}
		t=merge(a,merge(new treap(k+1,1LL*(k+1)*x),b));
	}
	printf("%I64d\n",solve(t).second);
	return 0;
}