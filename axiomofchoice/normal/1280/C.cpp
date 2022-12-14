#include <bits/stdc++.h>
using namespace std;
typedef long long ll; //typedef __int128 lll;
typedef pair<int,int> pii;
typedef double lf;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define qwq {cout<<"qwq"<<endl;}
const int N=200010;
const int inf=1e9;
const int mod=1000000007;
#define int ll
bool vis[N];
vector<pii> a[N];
int T,n,son[N],fa[N];
#define f(x,y) (s[x][y]=='A')
#define to first
#define len second
ll big,small;
int dfs(int x){
	vis[x]=1;
	son[x]=1;
	for(auto p:a[x])
	if(!vis[p.to]){
		int t=dfs(p.to);
		son[x]+=t;
		big+=p.len*min(t,n-t);
	}
	else fa[x]=p.to;
	return son[x];
}
void dfs2(int x){
	int cnt=0;
	for(auto p:a[x])
	if(p.to!=fa[x])
		dfs2(p.to);
	for(auto p:a[x])
	if(p.to!=fa[x] && !vis[p.to])
		small+=p.len,cnt++;
	if(cnt%2==1)vis[x]=1;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n; n*=2;
		big=small=0;
		repeat(i,0,n-1){
			int x,y,z;
			cin>>x>>y>>z; x--,y--;
			a[x].push_back({y,z});
			a[y].push_back({x,z});
		}
		fill(vis,vis+n,0);
		dfs(0); fa[0]=-1;
		fill(vis,vis+n,0);
		dfs2(0);
		cout<<small<<' '<<big<<endl;
		repeat(i,0,n)a[i].clear();
	}
    return 0;
}