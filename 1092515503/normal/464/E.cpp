#include<bits/stdc++.h>
using namespace std;
const int mod1=1e9+7,mod2=1004535809;
const int N=100100;
int n,m,S,T,bin[20010000],tp,cnt,bit1[100200],bit2[100200];
int rt[100100],pre[100100];
#define lson seg[x].ch[0]
#define rson seg[x].ch[1]
#define mid ((l+r)>>1)
#define LSON lson,l,mid
#define RSON rson,mid+1,r
#define X x,l,r
struct SegTree{
	int ch[2],hs1,hs2;
	SegTree(){ch[0]=ch[1]=hs1=hs2=0;}
	SegTree(int len){hs1=bit1[len]-1,hs2=bit2[len]-1;}
	friend bool operator==(const SegTree&u,const SegTree&v){return u.hs1==v.hs1&&u.hs2==v.hs2;}
}seg[20010000];
inline int newnode(){return tp?bin[tp--]:++cnt;}
inline void recycle(int&x){seg[x]=SegTree(),bin[++tp]=x,x=0;}
void recycle(vector<int>&v){for(auto x:v)recycle(x);v.clear();}
vector<int>v,V[100100];
inline void pushup(int&x,int l,int r){
	if(!lson&&!rson)return recycle(x),v.pop_back();
	seg[x].hs1=(1ll*seg[rson].hs1*bit1[mid-l+1]+seg[lson].hs1)%mod1;
	seg[x].hs2=(1ll*seg[rson].hs2*bit2[mid-l+1]+seg[lson].hs2)%mod2;
}
bool ADD(int&x,int l,int r,int P){
	if(r<P)return false;
	int tmp=newnode();seg[tmp]=seg[x],v.push_back(x=tmp);
	if(l>=P){
		if(seg[x]==SegTree(r-l+1)){recycle(x),v.pop_back();return false;}
		if(l==r){seg[x].hs1=seg[x].hs2=1;return true;}
	}
	if(ADD(LSON,P))return pushup(X),true;
	if(ADD(RSON,P))return pushup(X),true;
	return pushup(X),false;
}
void iterate(int x,int l,int r){
	if(!x)return;
	if(l==r)printf("%d ",l);else iterate(RSON),iterate(LSON);
}
bool CMP(int x,int y,int l,int r){
	if(!x&&y)return true;
	if(x&&!y)return false;
	return seg[seg[x].ch[1]]==seg[seg[y].ch[1]]?
		CMP(seg[x].ch[0],seg[y].ch[0],mid+1,r):CMP(seg[x].ch[1],seg[y].ch[1],l,mid);
}
struct cmp{
bool operator()(const int&a,const int&b){
	return seg[rt[a]]==seg[rt[b]]?a<b:CMP(rt[a],rt[b],0,N);
}
};
set<int,cmp>s;
int head[100100],ecc;
struct node{int to,next,val;}edge[200100];
void ae(int u,int v,int w){
	edge[ecc].next=head[u],edge[ecc].to=v,edge[ecc].val=w,head[u]=ecc++;
	edge[ecc].next=head[v],edge[ecc].to=u,edge[ecc].val=w,head[v]=ecc++;
}
vector<int>u;
int main(){
	bit1[0]=bit2[0]=1;
	for(int i=1;i<=N;i++)bit1[i]=(bit1[i-1]<<1)%mod1,bit2[i]=(bit2[i-1]<<1)%mod2;
	memset(rt,-1,sizeof(rt)),memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	for(int i=1,x,y,z;i<=m;i++)scanf("%d%d%d",&x,&y,&z),ae(x,y,z);
	scanf("%d%d",&S,&T);
	rt[S]=0,s.insert(S);
	while(!s.empty()){
		int x=*s.begin();s.erase(s.begin());
//		printf("%d:%d|",x,rt[x]);iterate(rt[x],0,N),puts("");
		for(int i=head[x],y;i!=-1;i=edge[i].next){
			y=edge[i].to;
			ADD(rt[0]=rt[x],0,N,edge[i].val);
//			printf("%d->%d:%d|",x,y,rt[0]),iterate(rt[0],0,N),puts("");
			if(rt[y]==-1)rt[y]=rt[0],swap(v,V[y]),pre[y]=x,s.insert(y);
			else if(cmp()(0,y))
				s.erase(y),recycle(V[y]),rt[y]=rt[0],swap(v,V[y]),pre[y]=x,s.insert(y);
			else recycle(v);
		}
	}
	if(rt[T]==-1){puts("-1");return 0;}
	printf("%d\n",seg[rt[T]].hs1);
	while(T!=S)u.push_back(T),T=pre[T];
	u.push_back(S),reverse(u.begin(),u.end());
	printf("%d\n",(int)u.size());
	for(auto x:u)printf("%d ",x);puts("");
	return 0;
}