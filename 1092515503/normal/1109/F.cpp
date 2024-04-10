#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,lim,a[1010][1010],dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
pair<int,int>p[1000100];
ll res;
namespace LCT{
	#define lson t[x].ch[0]
	#define rson t[x].ch[1]
	struct Link_Cut_Tree{
		int fa,ch[2];
		bool rev;
	}t[200100];
	inline int identify(int x){
		if(x==t[t[x].fa].ch[0])return 0;
		if(x==t[t[x].fa].ch[1])return 1;
		return -1;
	}
	inline void REV(int x){t[x].rev^=1,swap(lson,rson);}
	inline void pushdown(int x){
		if(!t[x].rev)return;
		if(lson)REV(lson);
		if(rson)REV(rson);
		t[x].rev=0;
	}
	inline void rotate(int x){
		register int y=t[x].fa,z=t[y].fa,dirx=identify(x),diry=identify(y),b=t[x].ch[!dirx];
		if(diry!=-1)t[z].ch[diry]=x;t[x].fa=z;
		if(b)t[b].fa=y;t[y].ch[dirx]=b;
		t[y].fa=x,t[x].ch[!dirx]=y;
	}
	inline void pushall(int x){if(identify(x)!=-1)pushall(t[x].fa);pushdown(x);}
	inline void splay(int x){for(pushall(x);identify(x)!=-1;rotate(x))if(identify(t[x].fa)!=-1)rotate(identify(x)==identify(t[x].fa)?t[x].fa:x);}
	inline void access(int x){for(register int y=0;x;x=t[y=x].fa)splay(x),rson=y;}
	inline void makeroot(int x){access(x),splay(x),REV(x);}
	inline int findroot(int x){access(x),splay(x),pushdown(x);while(lson)x=lson,pushdown(x);splay(x);return x;}
	inline void split(int x,int y){makeroot(x),access(y),splay(y);}
	inline bool link(int x,int y){if(findroot(x)==findroot(y))return false;makeroot(x),t[x].fa=y;return true;}
	inline void cut(int x,int y){split(x,y),t[y].ch[0]=t[x].fa=0;}
	#undef lson
	#undef rson
} 
namespace SG{
	#define lson x<<1
	#define rson x<<1|1
	#define mid ((l+r)>>1)
	struct SegTree{
		int mn,num,tag;
	}seg[800100];
	void ADD(int x,int y){seg[x].mn+=y,seg[x].tag+=y;}
	void pushdown(int x){ADD(lson,seg[x].tag),ADD(rson,seg[x].tag),seg[x].tag=0;}
	void pushup(int x){
		seg[x].mn=min(seg[lson].mn,seg[rson].mn),seg[x].num=0;
		if(seg[x].mn==seg[lson].mn)seg[x].num+=seg[lson].num;
		if(seg[x].mn==seg[rson].mn)seg[x].num+=seg[rson].num;
	}
	void build(int x,int l,int r){
		if(l==r){seg[x].mn=0,seg[x].num=1;return;}
		build(lson,l,mid),build(rson,mid+1,r),pushup(x);
	}
	void modify(int x,int l,int r,int L,int R,int val){
		if(l>R||r<L)return;
		if(L<=l&&r<=R){ADD(x,val);return;}
		pushdown(x),modify(lson,l,mid,L,R,val),modify(rson,mid+1,r,L,R,val),pushup(x); 
	}
	int query(int x,int l,int r,int L,int R){
		if(l>R||r<L)return 0;
		if(L<=l&&r<=R)return seg[x].mn==1?seg[x].num:0;
		pushdown(x);
		return query(lson,l,mid,L,R)+query(rson,mid+1,r,L,R);
	}
	#undef lson
	#undef rson
	#undef mid
}
#define P a[x+dx[i]][y+dy[i]]
int main(){
	scanf("%d%d",&n,&m),lim=n*m;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&a[i][j]),p[a[i][j]]=make_pair(i,j);
	SG::build(1,1,lim);
	for(int l=1,r=1;l<=lim;l++){
		while(r<=lim){
			int x=p[r].first,y=p[r].second;
			int cnt=0;
			for(int i=0;i<4;i++){
				if(!(P>=l&&P<r))continue;
				cnt++;
				if(LCT::link(r,P))continue;
				for(i--;i>=0;i--)if(P>=l&&P<r)LCT::cut(r,P);
				cnt=-1;
				break;
			}
			if(cnt==-1)break;
			SG::modify(1,1,lim,r,lim,-cnt);
			SG::modify(1,1,lim,r,r,r-l+1);
			r++;
		}
		res+=SG::query(1,1,lim,l,r-1);
		SG::modify(1,1,lim,l,r-1,-1);
		int x=p[l].first,y=p[l].second;
		for(int i=0;i<4;i++)if(P>=l&&P<r)LCT::cut(l,P),SG::modify(1,1,lim,P,lim,1);
	}
	printf("%lld\n",res);
	return 0;
}