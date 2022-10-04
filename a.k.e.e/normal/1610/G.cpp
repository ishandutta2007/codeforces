#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define pb push_back
#define mp make_pair
template <typename T> void chkmin(T &x,T y){y<x?x=y:T();}
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
template <typename T> void readint(T &x)
{
	int f=1;char c;x=0;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
	x*=f;
}
/*const int MOD=;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}*/
const int MAXN=300005;

int n;
char a[MAXN];
bool sel[MAXN],res[MAXN];
int nxt[MAXN],sta[MAXN],top,to[MAXN];
int head[MAXN],tail[MAXN],go[MAXN];
void work(int l)
{
	int r=to[l];
	vector<int> al;
	for(int x=nxt[l+1];x<r;x=nxt[to[x]+1])work(x),al.pb(x);
	head[l]=tail[l]=r;
	reverse(al.begin(),al.end());
	for(auto x:al)
	{
		bool fl=1;
		for(int u=head[x],v=head[l];u||v;u=go[u],v=go[v])
			if(v!=r && a[u]>a[v]){fl=0;break;}
			else if(v==r || a[u]<a[v]){fl=1;break;}
		if(fl)go[tail[x]]=head[l],head[l]=head[x];
	}
	go[l]=head[l],head[l]=l;
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	scanf("%s",a+1);n=strlen(a+1);
	vector<int> tr;tr.pb(0);
	for(int i=1,cnt=0;i<=n;++i)
		if(a[i]=='(')++cnt;
		else if(!cnt)sel[i]=1,tr.pb(i);
		else --cnt;
	for(int i=n;i;--i)
	{
		if(sel[i])continue;
		if(a[i]==')')sta[++top]=i;
		else if(top)to[sta[top]]=i,to[i]=sta[top],--top;
		else sel[i]=1;
	}
	for(int kk=1;kk<tr.size();++kk)
	{
		int l=tr[kk-1],r=tr[kk];
		to[l]=r,to[r]=l;
		nxt[r]=r;
		for(int i=r-1;i>=l;--i)nxt[i]=(sel[i]?nxt[i+1]:i);
		memset(go+l,0,sizeof(int)*(r-l+1));
		memset(head+l,0,sizeof(int)*(r-l+1));
		memset(tail+l,0,sizeof(int)*(r-l+1));
		work(l);
		for(int u=go[l];u!=r;u=go[u])res[u]=1;
	}
	for(int i=1;i<=n;++i)
		if(sel[i]||res[i])putchar(a[i]);
	return 0;
}