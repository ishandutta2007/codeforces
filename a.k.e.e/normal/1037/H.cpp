#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:TYPE();}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:TYPE();}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=200005;

int n,m;
char str[MAXN],a[MAXN];
int ch[MAXN][26],fa[MAXN],len[MAXN],stot=1,las=1;
vector<int> G[MAXN];
int rt[MAXN],lch[MAXN<<5],rch[MAXN<<5],ctot;
int modify(int l,int r,int x)
{
	int rt=++ctot;
	if(l==r)return rt;
	int mid=(l+r)>>1;
	if(x<=mid)lch[rt]=modify(l,mid,x);
	else rch[rt]=modify(mid+1,r,x);
	return rt;
}
int merge(int u,int v,int l,int r)
{
	if(!u || !v || u==v)return u|v;
	int rt=++ctot,mid=(l+r)>>1;
	lch[rt]=merge(lch[u],lch[v],l,mid);
	rch[rt]=merge(rch[u],rch[v],mid+1,r);
	return rt;
}
bool query(int id,int l,int r,int ql,int qr)
{
	if(!id)return 0;
	if(l==ql && r==qr)return 1;
	int mid=(l+r)>>1;
	if(qr<=mid)return query(lch[id],l,mid,ql,qr);
	if(ql>mid)return query(rch[id],mid+1,r,ql,qr);
	return query(lch[id],l,mid,ql,mid) || query(rch[id],mid+1,r,mid+1,qr);
}
void extend(int c)
{
	int p=las,np=++stot;las=np,len[np]=len[p]+1;
	rt[np]=modify(1,n,len[np]);
	for(;p && !ch[p][c];p=fa[p])ch[p][c]=np;
	if(!p){fa[np]=1;return;}
	int q=ch[p][c];
	if(len[q]==len[p]+1){fa[np]=q;return;}
	int nq=++stot;
	len[nq]=len[p]+1;
	fa[nq]=fa[q];
	memcpy(ch[nq],ch[q],sizeof(ch[q]));
	fa[q]=fa[np]=nq;
	for(;ch[p][c]==q;p=fa[p])ch[p][c]=nq;
}
void dfs(int u)
{
	for(auto v:G[u])
	{
		dfs(v);
		rt[u]=merge(rt[u],rt[v],1,n);
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int Q,l,r;
	scanf("%s",str+1);
	n=strlen(str+1);
	for(int i=1;i<=n;++i)extend(str[i]-'a');
	for(int i=1;i<=stot;++i)G[fa[i]].pb(i);
	dfs(1);
/*for(int i=1;i<=stot;++i)
{
	cerr<<fa[i]<<" "<<ch[i][0]<<" "<<ch[i][1]<<"; ";
	for(int j=1;j<=n;++j)cerr<<query(rt[i],1,n,j,j);cerr<<endl;
}*/
	readint(Q);
	while(Q--)
	{
		readint(l),readint(r);scanf("%s",a+1);m=strlen(a+1);
		int cur=1;
		pii ans=mp(0,0);
		for(int i=1;i<=m+1;++i)
		{
			int c=(i>m?-1:a[i]-'a');
			for(int j=c+1;j<26;++j)
				if(query(rt[ch[cur][j]],1,n,l+i-1,r))
					chkmax(ans,mp(i,26-j));
			if(c>=0 && query(rt[ch[cur][c]],1,n,l+i-1,r))cur=ch[cur][c];
			else break;
		}
		if(!ans.x)printf("-1\n");
		else
		{
			for(int i=1;i<ans.x;++i)putchar(a[i]);
			putchar(26-ans.y+'a');
			putchar('\n');
		}
	}
	return 0;
}