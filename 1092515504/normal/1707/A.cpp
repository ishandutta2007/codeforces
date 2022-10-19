/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
int T,n,m,a[100100];
char s[100100];
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
int mn[400100],tag[400100];
void ADD(int x,int y){mn[x]+=y,tag[x]+=y;}
void pushdown(int x){ADD(lson,tag[x]),ADD(rson,tag[x]),tag[x]=0;}
void pushup(int x){mn[x]=min(mn[lson],mn[rson]);}
void modify(int x,int l,int r,int L,int R,int val){
	if(l>R||r<L)return;
	if(L<=l&&r<=R)return ADD(x,val);
	pushdown(x),modify(lson,l,mid,L,R,val),modify(rson,mid+1,r,L,R,val),pushup(x);
}
void reset(int x,int l,int r,int P,int val){
	if(l==r)mn[x]=val,tag[x]=0;
	else pushdown(x),P<=mid?reset(lson,l,mid,P,val):reset(rson,mid+1,r,P,val),pushup(x);
}
int getfir(int x,int l,int r){
	if(mn[x]>0)return -1;
	if(l==r)return l;
	pushdown(x);
	int ret=getfir(lson,l,mid);
	return ret==-1?getfir(rson,mid+1,r):ret;
}
void build(int x,int l,int r){
	mn[x]=0x3f3f3f3f,tag[x]=0;
	if(l!=r)build(lson,l,mid),build(rson,mid+1,r);
}
bool red[400100];
void mina(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),s[i]='0',red[i]=false;
	build(1,1,n);
	for(int i=1,j=1;;){
		for(;j<=n&&m;j++){
			if(a[j]>m)reset(1,1,n,j,a[j]-m),m--,red[j]=true;
			else reset(1,1,n,j,0x3f3f3f3f);
			s[j]='1';
		}
		if(j>n)break;
		while(!red[i])i++;
		s[i]='0',m++,reset(1,1,n,i,0x3f3f3f3f),red[i]=false,modify(1,1,n,i,j-1,-1);
		while(true){
			int P=getfir(1,1,n);
			if(P==-1)break;
			m++,red[P]=false,reset(1,1,n,P,0x3f3f3f3f),modify(1,1,n,P,j-1,-1);
		}
	}
	s[n+1]=0,printf("%s\n",s+1);
}
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}
/*
1
5 2
5 1 2 4 3
*/