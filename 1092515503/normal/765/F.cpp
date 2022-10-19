#include<bits/stdc++.h>
using namespace std;
const int N=1e9+3;
#define lson seg[x].ch[0]
#define rson seg[x].ch[1]
#define mid ((l+r)>>1)
int n,m,a[100100],rt,cnt;
struct SegTree{int ch[2],mx;}seg[3200100];
void modify(int&x,int l,int r,int P,int val){
	if(!x)x=++cnt;seg[x].mx=val;
	if(l!=r)P<=mid?modify(lson,l,mid,P,val):modify(rson,mid+1,r,P,val); 
}
int query(int x,int l,int r,int L,int R){
	if(!x||l>R||r<L)return 0;
	if(L<=l&&r<=R)return seg[x].mx;
	return max(query(lson,l,mid,L,R),query(rson,mid+1,r,L,R));
}
int res[300100];
vector<pair<int,int> >v[100100];
int t[100100];
void MOD(int x,int y){/*printf("MOD:%d,%d\n",x,y);*/while(x)t[x]=min(t[x],y),x-=x&-x;}
int ASK(int x){int ret=0x3f3f3f3f;while(x<=n)ret=min(ret,t[x]),x+=x&-x;return ret;}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%d",&m);
	memset(t,0x3f,sizeof(t));
	for(int i=1,l,r;i<=m;i++)scanf("%d%d",&l,&r),v[r].emplace_back(l,i);
	for(int i=1,p;i<=n;i++){
//		printf("%d:\n",i);
		p=query(rt,0,N,a[i],N);if(p)MOD(p,a[p]-a[i]);
		while(p&&a[p]!=a[i]){
			int q=query(rt,0,N,a[i],a[i]+((a[p]-a[i])>>1));
			if(!q)break;
			MOD(q,a[q]-a[i]),p=q;
		}
		p=query(rt,0,N,0,a[i]);if(p)MOD(p,a[i]-a[p]);
		while(p&&a[p]!=a[i]){
			int q=query(rt,0,N,a[i]-((a[i]-a[p])>>1),a[i]);
			if(!q)break;
			MOD(q,a[i]-a[q]),p=q;
		}
		modify(rt,0,N,a[i],i);
		for(auto x:v[i])res[x.second]=ASK(x.first);
	}
	for(int i=1;i<=m;i++)printf("%d\n",res[i]);
	return 0;
}