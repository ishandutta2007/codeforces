// Author: wlzhouzhuan
#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define mset(s,t) memset(s,t,sizeof(s))
#define mcpy(s,t) memcpy(s,t,sizeof(t))
#define SZ(x) ((int)x.size())
#define pb push_back
#define eb emplace_back
#define fir first
#define sec second

template<class T1,class T2>bool ckmax(T1 &a,T2 b){if(a<b)return a=b,1;else return 0;}
template<class T1,class T2>bool ckmin(T1 &a,T2 b){if(a>b)return a=b,1;else return 0;}

inline int read(){
	int x=0,f=0;char ch=getchar();
	while(!isdigit(ch))f|=ch=='-',ch=getchar();
	while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
	return f?-x:x;
}
template<typename T>void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)print(x/10);
	putchar(x%10+'0');
}
template<typename T>void print(T x,char ch){
	print(x),putchar(ch);
}

const int N=1000005;

vector<int> adj[N];
int maxp[N],sz[N],rt,n;
ll ans;

void dfs1(int u,int fa){
	maxp[u]=0,sz[u]=1;
	for(auto v:adj[u]){
		if(v==fa)continue;
		dfs1(v,u),sz[u]+=sz[v];
		ckmax(maxp[u],sz[v]);
	}
	ckmax(maxp[u],n-sz[u]);
	if(maxp[u]<maxp[rt])rt=u;
}
void dfs2(int u,int fa){
	sz[u]=1;
	for(auto v:adj[u]){
		if(v==fa)continue;
		dfs2(v,u),sz[u]+=sz[v];
	}
	if(u!=rt)ans+=sz[u];
}

int main(){
	n=read();
	rep(i,2,n){
		int fa=read();
		adj[fa].pb(i),adj[i].pb(fa);
	}
	maxp[rt=0]=n,dfs1(1,0),dfs2(rt,0);
	// printf("rt=%d\n",rt);
	vector<int> tmp;
	for(auto u:adj[rt])tmp.pb(sz[u]);
	sort(tmp.begin(),tmp.end());
	// for(auto it:tmp)printf("%d ",it);puts("");
	// printf("cur ans=%lld\n",ans);
	bitset<N> bs;bs.set(0);
	for(int i=0;i<SZ(tmp);i++){
		int j=i;while(j+1<SZ(tmp)&&tmp[i]==tmp[j+1])j++;
		int len=j-i+1;
		for(int k=1;k<=len;k<<=1){
			bs|=bs<<k*tmp[i];
			len-=k;
		}
		if(len)bs|=bs<<len*tmp[i];
		i=j;
	}
	for(int i=(n-1)/2;i>=0;i--){
		if(bs.test(i)){
			ans+=1ll*(i+1)*(n-i);
			break;
		}
	}
	print(ans,'\n');
	return 0;
}