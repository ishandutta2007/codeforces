#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,h[300100],a[300100];
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
ll tag[1200100];
void pushdown(int x){tag[lson]=max(tag[lson],tag[x]),tag[rson]=max(tag[rson],tag[x]);}
void Setval(int x,int l,int r,int L,int R,ll val){
	if(l>R||r<L)return;
	if(L<=l&&r<=R){tag[x]=max(tag[x],val);return;}
	pushdown(x),Setval(lson,l,mid,L,R,val),Setval(rson,mid+1,r,L,R,val);
}
ll Askval(int x,int l,int r,int P){
	if(l>P||r<P)return 0;
	if(l==r)return tag[x];
	pushdown(x);return Askval(lson,l,mid,P)+Askval(rson,mid+1,r,P);
}
ll mx[1200100];
void pushup(int x){mx[x]=max(mx[lson],mx[rson]);}
void modify(int x,int l,int r,int P,ll val){
	if(l>P||r<P)return;
	if(l==r){mx[x]=val;return;}
	modify(lson,l,mid,P,val),modify(rson,mid+1,r,P,val),pushup(x);
}
ll query(int x,int l,int r,int L,int R){
	if(l>R||r<L)return 0xc0c0c0c0c0c0c0c0; 
	if(L<=l&&r<=R)return mx[x];
	return max(query(lson,l,mid,L,R),query(rson,mid+1,r,L,R));
}
ll f[300100];
int L[300100],R[300100],stk[300100],tp;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&h[i]);
	for(int i=1;i<=n;i++){
		while(tp&&h[stk[tp]]>h[i])R[stk[tp--]]=i-1;
		L[i]=stk[tp]+1,stk[++tp]=i;
	}
	while(tp)R[stk[tp--]]=n;
//	for(int i=1;i<=n;i++)printf("[%d,%d]",L[i],R[i]);puts("");
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	memset(mx,0xc0,sizeof(mx)),modify(1,1,n,1,0),memset(tag,0xc0,sizeof(tag));
	for(int i=1;i<=n;i++){
		f[i]=max(query(1,1,n,L[i],i)+a[i],Askval(1,1,n,i));
		modify(1,1,n,i+1,f[i]),Setval(1,1,n,i+1,R[i],f[i]); 
	}
	printf("%lld\n",f[n]);
	return 0;
}