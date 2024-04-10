#include<bits/stdc++.h>
using namespace std;
int n,K,f[20100],g[20100],a[20100],stk[20100],rt[20100],cnt,tp;
struct Line{
	int k,b;
	Line(){}
	Line(int K,int B){k=K,b=B;}
	int operator()(const int x)const{return k*x+b;}
};
#define lson seg[x].ch[0]
#define rson seg[x].ch[1]
#define mid ((l+r)>>1)
struct SegTree{int ch[2];Line l;}seg[1001000];
void insert(int&x,int y,int l,int r,Line V){
//	printf("INSERT:%d,%d[%d,%d](%dx+%d)\n",x,y,l,r,V.k,V.b);
	if(l>r)return;
	x=++cnt;if(!y){seg[x].l=V;return;}
	seg[x]=seg[y];
	if(seg[x].l(mid)>V(mid))swap(seg[x].l,V);
	if(seg[x].l(l)>V(l))insert(seg[x].ch[0],seg[y].ch[0],l,mid-1,V);
	if(seg[x].l(r)>V(r))insert(seg[x].ch[1],seg[y].ch[1],mid+1,r,V);
}
int query(int x,int l,int r,int P){
//	printf("QUERY:%d[%d,%d](%d,%d):%d\n",x,l,r,seg[x].l.k,seg[x].l.b,P);
	if(l>r||!x)return 0x3f3f3f3f;
	int ret=seg[x].l(P);
	if(P>mid)ret=min(ret,query(rson,mid+1,r,P));
	if(P<mid)ret=min(ret,query(lson,l,mid-1,P));
	return ret;
}
#undef lson
#undef rson
#undef mid 
struct Hull:deque<int>{
int query(int K)const{
	int l=0,r=size()-1;
	while(l<r){
		int mid=(l+r)>>1;
		int u=*(begin()+mid),v=*(begin()+mid+1);
		if(g[u]-K*u<=g[v]-K*v)r=mid;else l=mid+1;
	}
	int x=*(begin()+l);
	return g[x]-K*x;
}
void PUSH_BACK(int i){
	while(size()>=2){
		int k=*(rbegin()+1),j=*rbegin();
		if(1ll*(g[i]-g[k])*(j-k)>1ll*(g[j]-g[k])*(i-k))break;
		pop_back();
	}
	push_back(i);
}
void PUSH_FRONT(int k){
	while(size()>=2){
		int i=*(begin()+1),j=*begin();
		if(1ll*(g[i]-g[k])*(j-k)>1ll*(g[j]-g[k])*(i-k))break;
		pop_front();
	}
	push_front(k);
}
void merge(Hull&h){
	if(size()>=h.size()){for(auto i:h)PUSH_BACK(i);h.clear();}
	else{for(auto it=rbegin();it!=rend();it++)h.PUSH_FRONT(*it);clear(),swap(h);}
}
}h[20100];
void DP(){
	for(int i=1;i<=n;i++){
		while(tp>=2&&a[stk[tp-1]]<=a[i])h[tp-1].merge(h[tp]),tp--;
		if(!tp||a[stk[tp]]>a[i])tp++;
		h[tp].PUSH_BACK(i-1),stk[tp]=i;
//		for(int j=1;j<=tp;j++){printf("[");for(auto x:h[j])printf("%d ",x);printf("]");}puts("");
		insert(rt[tp],rt[tp-1],1,n,Line(a[i],h[tp].query(a[i])));
		f[i]=query(rt[tp],1,n,i);
	}//puts("");
//	for(int i=1;i<=n;i++)printf("%d ",f[i]);puts("");
	while(tp)h[tp].clear(),stk[tp]=rt[tp]=0,tp--;
	for(int i=1;i<=cnt;i++)seg[i].ch[0]=seg[i].ch[1]=0;cnt=0;
}
int main(){
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	memset(f,0x3f,sizeof(f)),f[0]=0;
	while(K--)swap(f,g),DP();
	printf("%d\n",f[n]);
	return 0;
}