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

#define N 400020
vector<tuple<int,int,int> > G[N];
vector<int> ans[N];
vector<bool> vis[N];
int n,a[N],m;
map<int,int> mp;
inline void adde(int u,int v,int x,int y){
	G[u].emplace_back(v,x,y);
	G[v].emplace_back(u,x,y);
}
int zz;
void dfs(int u){
	while(!G[u].empty()){
		auto [v,x,y]=G[u].back();
		G[u].pop_back();
		if(vis[x][y])continue;
		vis[x][y]=1;
		dfs(v);
		zz^=1;
		ans[x][y]=zz;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	m=n;
	for(int i=1;i<=n;++i){
		int k,x;
		cin>>k;
		ans[i].resize(k);
		vis[i].resize(k);
		for(int j=0;j<k;++j){
			cin>>x;
			if(!mp.count(x))mp[x]=++m;
			int v=mp[x];
			adde(v,i,i,j);
		}
	}
	for(int i=1;i<=m;++i){
		if(G[i].size()%2==1){
			cout<<"NO\n";
			return 0;
		}
	}
	for(int i=1;i<=m;++i){
		dfs(i);
	}
	cout<<"YES\n";
	for(int i=1;i<=n;++i){
		for(auto x:ans[i]){
			cout<<(x?'R':'L');
		}
		cout<<'\n';
	}
	return 0;
}