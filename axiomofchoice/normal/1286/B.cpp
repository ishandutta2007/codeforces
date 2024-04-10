#include <bits/stdc++.h>
using namespace std;
#define lll __int128
typedef long long ll;
typedef pair<int,int> pii;
typedef double lf; const lf err=1e-7;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define qwq {cout<<"qwq"<<endl;}
#define orz(x) {cout<<#x": "<<x<<endl;}
const int N=2010;
const int inf=1e9;
const int mod=1e9+7;
//#define int ll
int son[N],ans[N],dfn[N],fa[N],index;
int n,c[N],all[N];
vector<int> a[N];
void dfs(int x){
	son[x]=1;
	dfn[x]=++index;
	for(auto p:a[x])
	if(fa[p]==x){
		dfs(p);
		son[x]+=son[p];
	}
	if(c[x]>son[x]-1){cout<<"NO"<<endl;exit(0);}
	sort(all+dfn[x]+1,all+dfn[x]+son[x]);
	//0 2 1
	//cout<<x<<' '<<c[x]<<endl;
	if(c[x]==0)ans[x]=1;
	else ans[x]=all[dfn[x]+c[x]]+1;
	repeat(i,0,n+1){
		if(all[i]>=ans[x])all[i]++;
		if(i!=x && ans[i]>=ans[x])ans[i]++;
	}
	all[dfn[x]]=ans[x];
	//repeat(i,1,n+1)cout<<all[i]<<' ';cout<<endl;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	repeat(i,1,n+1){
		cin>>fa[i]>>c[i];
		a[fa[i]].push_back(i);
	}
	int rt=a[0][0];
	index=0;
	dfs(rt);
	cout<<"YES"<<endl;
	repeat(i,1,n+1)cout<<ans[i]<<' ';
	return 0;
}