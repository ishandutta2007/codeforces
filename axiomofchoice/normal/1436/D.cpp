#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
const int N=200010; typedef long long ll; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;}
#define int ll
int cnt[N],sum[N],mx[N];
vector<int> a[N];
void dfs(int x){
	if(a[x].empty())cnt[x]=1;
	for(auto p:a[x]){
		dfs(p);
		sum[x]+=sum[p];
		mx[x]=max(mx[x],mx[p]);
		cnt[x]+=cnt[p];
	}
	mx[x]=max(mx[x],(sum[x]+cnt[x]-1)/cnt[x]);
}
void Solve(){
	int n=read();
	repeat(i,2,n+1){
		a[read()].push_back(i);
	}
	repeat(i,1,n+1)sum[i]=read();
	dfs(1);
	cout<<mx[1]<<endl;
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; //T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}