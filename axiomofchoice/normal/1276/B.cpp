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
//#define int ll
vector<int> a[N];
set<int> f;
bool vis[N];
int n,m,s,t,T;
set<int> ans;
int dfs(int x){
	int ans=1;
	vis[x]=1;
	for(int p:a[x]){
		if(p==s || p==t)
			f.insert(p);
		if(!vis[p])ans+=dfs(p);
	}
	return ans;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>m>>s>>t; s--,t--;
		repeat(i,0,m){
			int u,v; cin>>u>>v; u--,v--;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		repeat(i,0,n)vis[i]=0; vis[s]=1; vis[t]=1;
		int sum[2]={0,0},sum2=0;
		ans.clear();
		repeat(i,0,n)
		if(!vis[i]){
			f.clear();
			int t1=dfs(i);
			int t2=f.count(s);
			int t3=f.count(t);//cout<<i+1<<' '<<t1<<' '<<t2<<' '<<t3<<endl;
			if(t2+t3==1)
				sum[t2]+=t1;
		}
		//cout<<sum[0]<<' '<<sum[1]<<endl;
		cout<<(ll)sum[0]*sum[1]<<endl;;
		repeat(i,0,n)a[i].clear();
	}
    return 0;
}