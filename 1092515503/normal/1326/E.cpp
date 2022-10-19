#include<bits/stdc++.h>
using namespace std;
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
int n,p[300100],q[300100],res,rev[300100];
struct node{
	int mn,tag;
}seg[1201000];
void ADD(int x,int y){
	seg[x].mn+=y,seg[x].tag+=y;
}
void pushdown(int x){
	ADD(lson,seg[x].tag),ADD(rson,seg[x].tag),seg[x].tag=0;
}
void pushup(int x){
	seg[x].mn=min(seg[lson].mn,seg[rson].mn);
}
void modify(int x,int l,int r,int L,int R,int val){
	if(l>R||r<L)return;
	if(L<=l&&r<=R){ADD(x,val);return;}
	pushdown(x),modify(lson,l,mid,L,R,val),modify(rson,mid+1,r,L,R,val),pushup(x);
}
bool decrease(){
	modify(1,1,n,1,rev[res],-1);
	if(seg[1].mn>=0)return true;
	modify(1,1,n,1,rev[res],1);//erase the influence of the previous operation 
	return false;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]),rev[p[i]]=i;
	for(int i=1;i<=n;i++)scanf("%d",&q[i]);
	res=n;
	for(int i=1;i<=n;i++){
		while(decrease())res--;
		printf("%d ",res);
		modify(1,1,n,1,q[i],1);
	}
	return 0;
}