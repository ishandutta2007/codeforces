#include<bits/stdc++.h>
using namespace std;
#define mid ((l+r)>>1)
typedef long long ll;
int n,m,root[200100],bin[1001000],tp,cnt,val[200100];
ll res;
struct node{
	int lson,rson,sum;
}seg[20010000];
void newnode(int &x){
	if(!tp)x=++cnt;
	else x=bin[tp--];
}
void add(int &x,int l,int r,int P,int val){
	if(l>P||r<P)return;
	if(!x)newnode(x);
	seg[x].sum+=val;
	if(l!=r)add(seg[x].lson,l,mid,P,val),add(seg[x].rson,mid+1,r,P,val);
	if(!seg[x].sum)bin[++tp]=x,x=0;
}
void ADD(int x,int y,int k){
	while(x<=n)add(root[x],1,n,y,k),x+=x&-x;
}
int ask(int x,int l,int r,int L,int R){
	if(!x||l>R||r<L)return 0;
	if(L<=l&&r<=R)return seg[x].sum;
	return ask(seg[x].lson,l,mid,L,R)+ask(seg[x].rson,mid+1,r,L,R);
}
int ASK(int x,int L,int R){
	ll ret=0;
	while(x)ret+=ask(root[x],1,n,L,R),x-=x&-x;
	return ret;
}
ll SWAP(int x,int y){
	if(x==y)return res;
	if(x>y)swap(x,y);
	ADD(x,val[x],-1),ADD(y,val[y],-1);
	if(val[x]<val[y])res++,res+=(ASK(y-1,val[x],val[y])-ASK(x,val[x],val[y]))<<1;
	else res--,res-=(ASK(y-1,val[y],val[x])-ASK(x,val[y],val[x]))<<1;
	swap(val[x],val[y]);
	ADD(x,val[x],1),ADD(y,val[y],1);
	return res;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)ADD(i,val[i]=i,1);
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),printf("%lld\n",SWAP(x,y));
	return 0;
}