#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[150100],p[150100];
ll res[150100];
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
struct SegBeat{
	int mx,mmx,mxc,tag,gat,sz;ll sum;
	SegBeat(){sum=tag=-1,sz=gat=0;}
}seg[600100];
void pushup(int x){
	if(seg[lson].sum==-1&&seg[rson].sum==-1){seg[x].sum=-1;return;}
	if(seg[lson].sum==-1){seg[x]=seg[rson],seg[x].gat=0,seg[x].tag=-1;return;}
	if(seg[rson].sum==-1){seg[x]=seg[lson],seg[x].gat=0,seg[x].tag=-1;return;}
	seg[x].mx=max(seg[lson].mx,seg[rson].mx),seg[x].mmx=-1,seg[x].mxc=0,seg[x].sum=seg[lson].sum+seg[rson].sum,seg[x].sz=seg[lson].sz+seg[rson].sz;
	if(seg[x].mx!=seg[lson].mx)seg[x].mmx=max(seg[x].mmx,seg[lson].mx);else seg[x].mxc+=seg[lson].mxc,seg[x].mmx=max(seg[x].mmx,seg[lson].mmx);
	if(seg[x].mx!=seg[rson].mx)seg[x].mmx=max(seg[x].mmx,seg[rson].mx);else seg[x].mxc+=seg[rson].mxc,seg[x].mmx=max(seg[x].mmx,seg[rson].mmx);
}
void MOD(int x,int y){seg[x].sum-=1ll*(seg[x].mx-y)*seg[x].mxc,seg[x].mx=seg[x].tag=y;}
void ADD(int x,int y){seg[x].mx+=y,seg[x].gat+=y,seg[x].mmx+=y,seg[x].sum+=1ll*seg[x].sz*y;if(seg[x].tag!=-1)seg[x].tag+=y;}
void pushdown(int x){
	if(seg[lson].sum!=-1)ADD(lson,seg[x].gat);
	if(seg[rson].sum!=-1)ADD(rson,seg[x].gat);
	seg[x].gat=0;
	if(seg[x].tag==-1)return;
	if(seg[lson].sum!=-1&&seg[lson].mx>seg[x].tag)MOD(lson,seg[x].tag);
	if(seg[rson].sum!=-1&&seg[rson].mx>seg[x].tag)MOD(rson,seg[x].tag);
	seg[x].tag=-1;
}
void modifypos(int x,int l,int r,int P,int val){
	if(l>P||r<P)return;
	if(l==r){seg[x].mx=val,seg[x].mmx=-1,seg[x].sum=val,seg[x].mxc=1,seg[x].sz=1;return;}
	pushdown(x),modifypos(lson,l,mid,P,val),modifypos(rson,mid+1,r,P,val),pushup(x);
}
void modifymn(int x,int l,int r,int L,int R,int val){
	if(seg[x].mx<=val||seg[x].sum==-1||l>R||r<L)return;
	if(L<=l&&r<=R&&seg[x].mmx<val){MOD(x,val);return;}
	pushdown(x),modifymn(lson,l,mid,L,R,val),modifymn(rson,mid+1,r,L,R,val),pushup(x);
}
void modifyshift(int x,int l,int r,int L,int R){
	if(l>R||r<L||seg[x].sum==-1)return;
	if(L<=l&&r<=R){ADD(x,1);return;}
	pushdown(x),modifyshift(lson,l,mid,L,R),modifyshift(rson,mid+1,r,L,R),pushup(x);
}
void clear(int x,int l,int r){
	seg[x]=SegBeat();
	if(l!=r)clear(lson,l,mid),clear(rson,mid+1,r);
}
/*void iterate(int x,int l,int r){
	if(seg[x].sum==-1)return;
	printf("[%d,%d]:MX:%d CM:%d MM:%d SM:%d SZ:%d GT:%d TG:%d\n",l,r,seg[x].mx,seg[x].mxc,seg[x].mmx,seg[x].sum,seg[x].sz,seg[x].gat,seg[x].tag);
	if(l!=r)iterate(lson,l,mid),iterate(rson,mid+1,r);
}
void etareti(int x,int l,int r){
	if(seg[x].sum==-1)return;
	if(l!=r)pushdown(x),etareti(lson,l,mid),etareti(rson,mid+1,r),pushup(x);
	else printf("(%d:%d)",l,seg[x].mx);
}*/
int t[200100];
void BITADD(int x){while(x<=n)t[x]++,x+=x&-x;}
int BITSUM(int x){int ret=0;while(x)ret+=t[x],x-=x&-x;return ret;}
void func(){
	clear(1,1,n),memset(t,0,sizeof(t));
	for(int i=1;i<=n;i++){
		int Rmax=BITSUM(p[i]);
		modifymn(1,1,n,1,p[i]-1,Rmax);
		modifypos(1,1,n,p[i],i);
		modifyshift(1,1,n,p[i]+1,n);
//		printf("%d\n",seg[1].sum);
		res[i]+=seg[1].sum;
		BITADD(p[i]);
//		iterate(1,1,n),puts("");
//		etareti(1,1,n),puts("");
//		iterate(1,1,n),puts("");
	}
}
inline void read(int &x){
	x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
}
inline void print(ll x){
	if(x<=9)putchar('0'+x);
	else print(x/10),putchar('0'+x%10);
}
int main(){
	read(n);
	for(int i=1;i<=n;i++)read(a[i]),p[a[i]]=i;
	func();
	reverse(a+1,a+n+1);for(int i=1;i<=n;i++)p[a[i]]=i;
	func();
	for(int i=1;i<=n;i++)print(res[i]-1ll*i*i),putchar('\n');
	return 0;
}