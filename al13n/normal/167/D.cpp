#pragma comment(linker,"/STACK:256000000")
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <memory.h>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <iomanip>
using namespace std;
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,(int)(v).size())
#define iinf 1000000000
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define lng long long
#define eps 1e-10
#define EQ(a,b) (fabs((a)-(b))<eps)
#define SQ(a) ((a)*(a))
#define PI 3.14159265359
#define index asdindex
#define FI first
#define SE second
#define prev asdprev
#define PII pair<int,int> 
#define X first
#define Y second
#define unlink asdunlink
typedef unsigned char uchar;
typedef unsigned int uint;

struct node{
	int x,y;
	int use,not;
	node *l,*r;
} nodealloc[1000000];
int nodecnt;

node* alloc(int x,int y){
	node *n=nodealloc+nodecnt++;
	n->l=n->r=NULL;
	n->x=x;
	n->y=y;
	n->use=n->not=0;
	return n;
}

int getuse(node *n){
	if(n)
		return n->use;
	else
		return 0;
}

int getnot(node *n){
	if(n)
		return n->not;
	else
		return 0;
}

void post(node *n){
	if(!n)
		return;
	n->use=n->not=getuse(n->l)+getuse(n->r);
	if(n->l)
		n->use=max(n->use,n->l->not+getuse(n->r)+1);
	if(n->r)
		n->use=max(n->use,n->r->not+getuse(n->l)+1);
}

node *merge(node *l,node *r){
	if(!l)
		return r;
	if(!r)
		return l;
	if(l->y>r->y){
		l->r=merge(l->r,r);
		post(l);
		return l;
	}else{
		r->l=merge(l,r->l);
		post(r);
		return r;
	}
}

void split(int x,node *n,node *&l,node *&r){
	if(!n){
		l=r=NULL;
		return;
	}
	if(n->x<x){
		split(x,n->r,n->r,r);
		l=n;
	}else{
		split(x,n->l,l,n->l);
		r=n;
	}
	post(n);
}

node *root;
PII pts[110000];

const lng mod=iinf+9;

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);

	int n,k;
	cin>>n>>k;
	node *root=NULL;

	lng px,py;
	forn(i,k){
		cin>>px>>py;
		pts[i]=mp((int)px,(int)py);
	}

	lng A,B,C,D;
	cin>>A>>B>>C>>D;

	forn(i,n-k){
		lng x=(A*px+B)%mod;
		lng y=(C*py+D)%mod;
		pts[i+k]=mp((int)x,(int)y);
		px=x;
		py=y;
	}

	sort(pts,pts+n);

	forn(i,n){
		root=merge(root,alloc(pts[i].X,pts[i].Y));
	}

	int tc;
	cin>>tc;
	forn(qqq,tc){
		int L,R;
		cin>>L>>R;

		node *l,*m,*r;

		split(L,root,l,m);
		split(R+1,m,m,r);

		cout<<getuse(m)<<'\n';

		m=merge(m,r);
		root=merge(l,m);
	}

    return 0;
}