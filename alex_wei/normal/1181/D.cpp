/*
	Templates start.
	Powered by c++11.
	Author : Alex_Wei.
*/

#include <bits/stdc++.h>
using namespace std;

// IO templates.

char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
#ifdef __WIN64
	#define gc getchar()
#else
	#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
#endif
#define pc(x) (*O++=x)
#define flush() fwrite(obuf,O-obuf,1,stdout)

inline int read(){
	int x=0; char s=getchar();
	while(!isdigit(s))s=getchar();
	while(isdigit(s))x=(x<<1)+(x<<3)+(s-'0'),s=getchar();
	return x;
}
void print(int x) {if(x>9)print(x/10); pc(x%10+'0');}

#define ll long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))
#define mem(x,v) memset(x,v,sizeof(x))

/*
	Templates end.
	Please give me more points.
*/

const int N=5e5+5,inf=1e9;
struct Treap{
	int val[N],rd[N],num[N],size[N],son[N][2],cnt,R;
	int min(int a,int b){return a<b?a:b;}
	int max(int a,int b){return a>b?a:b;}
	void push(int x){size[x]=size[son[x][0]]+size[son[x][1]]+num[x];}
	void rotate(int &x,int d)
	{
		int t=son[x][d^1];
		son[x][d^1]=son[t][d];
		son[t][d]=x;
		push(x),push(t);
		x=t;
	}
	void ins(int &x,int v)
	{
		if(!x){
			x=++cnt;
			val[x]=v;
			num[x]=size[x]=1;
			rd[x]=rand();
			return;
		}
		if(val[x]==v){
			num[x]++,size[x]++;
			return;
		}
		int d=v>val[x];
		ins(son[x][d],v);
		if(rd[x]<rd[son[x][d]])rotate(x,d^1);
		push(x);
	}
	int find(int x,int v)
	{
		if(!x)return 0;
		if(v<=size[son[x][0]])return find(son[x][0],v);
		if(v<=size[son[x][0]]+num[x])return val[x];
		if(v>size[son[x][0]]+num[x])return find(son[x][1],v-size[son[x][0]]-num[x]);
	}
}tree;

int n,m,q,cnt[N];
vector <int> buc[N];
ll ans[N];
struct query{
	ll k,id;
	bool operator < (const query &v) const {
		return k<v.k;
	} 
}c[N];

int main(){
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)cnt[read()]++;
	for(int i=1;i<=m;i++)buc[cnt[i]].pb(i);
	for(int i=1;i<=q;i++)scanf("%lld",&c[i].k),c[i].id=i;
	sort(c+1,c+q+1);
	int pos=1; ll val=n,sz=0;
	for(int i=0;i<=n;i++){
		for(int it:buc[i])tree.ins(tree.R,it);
		sz+=buc[i].size();
		while(pos<=q&&val+sz>=c[pos].k)ans[c[pos].id]=tree.find(tree.R,c[pos++].k-val);
		val+=sz;
	}
	while(pos<=q)ans[c[pos].id]=tree.find(tree.R,(c[pos++].k-val-1)%m+1);
	for(int i=1;i<=q;i++)printf("%lld\n",ans[i]);
	return 0;
}