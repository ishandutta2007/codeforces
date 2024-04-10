#include<bits/stdc++.h>
using namespace std;
#define mid ((l+r)>>1)
int n,m,cnt,root[1000100],f[500100],las[500100],num[500100];
struct node{
	int lson,rson;
	pair<int,int>mn;
}seg[32001000];
void pushup(int x){
	seg[x].mn=min(seg[seg[x].lson].mn,seg[seg[x].rson].mn);
}
void build(int &x,int l,int r){
	x=++cnt;
	seg[x].mn=make_pair(0x3f3f3f3f,l);
	if(l==r)return;
	build(seg[x].lson,l,mid),build(seg[x].rson,mid+1,r),pushup(x);
}
void modify(int las,int &x,int l,int r,int P,int val){
	seg[x=++cnt]=seg[las];
	if(l==r){seg[x].mn=make_pair(val,P);return;}
	if(P<=mid)modify(seg[las].lson,seg[x].lson,l,mid,P,val);
	else modify(seg[las].rson,seg[x].rson,mid+1,r,P,val);
	pushup(x);
}
pair<int,int> query(int x,int l,int r,int L,int R){
	if(l>R||r<L)return make_pair(0x3f3f3f3f,0);
	if(L<=l&&r<=R)return seg[x].mn;
	return min(query(seg[x].lson,l,mid,L,R),query(seg[x].rson,mid+1,r,L,R));
}
int main(){
	scanf("%d",&n),memset(las,-1,sizeof(las));
	build(root[0],1,n);
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
		if(las[num[i]]==-1)root[2*i-1]=root[2*i-2];
		else modify(root[2*i-2],root[2*i-1],1,n,las[num[i]],0x3f3f3f3f);
		f[i]=las[num[i]],las[num[i]]=i;
		modify(root[2*i-1],root[2*i],1,n,i,f[i]);
	}
	scanf("%d",&m);
	for(int i=1,l,r;i<=m;i++){
		scanf("%d%d",&l,&r);
		pair<int,int>res=query(root[2*r],1,n,l,r);
		if(res.first>=l)puts("0");
		else printf("%d\n",num[res.second]);
	}
	return 0;
}
/*
6
1 1 2 3 2 4
2
4 5
5 5
*/