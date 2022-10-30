#include<bits/stdc++.h>
#define N 1001000
#define M 510
#define Q 998244353
using namespace std;
int f[N],a[N];
long long dp[M][M];
vector<int> v[510];
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void dp_reset(int n){
	for(int i=0;i<=n;i++){
		for(int j=i;j<=n;j++){
			dp[i][j]=-1;
		}
	}
}
long long solve(vector<int>& seq,int l,int r){
	if(l==r) return 1;
	if(dp[l][r]>=0) return dp[l][r];
	int mn=l;
	long long ans=0;
	for(int i=l;i<r;i++){
		if(seq[i]<seq[mn]) mn=i;
		ans+=solve(seq,l,mn)*solve(seq,mn+1,i+1)%Q*solve(seq,i+1,r)%Q;
	}
	return dp[l][r]=ans%Q;
}
int main(){
	int n,m;
	long long ans=1;
	bool gg=false;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
		v[a[i]].push_back(i);
		f[i]=i;
	}
	f[0]=0;
	f[m+1]=m+1;
	v[0].push_back(0);
	v[0].push_back(m+1);
	for(int i=n;i>=0 && !gg;i--){
		for(int j=0;j+1<v[i].size() && !gg;j++){
			if(v[i][j]+1==v[i][j+1]){
				f[v[i][j]]=v[i][j]+1;
				continue;
			}
			int u=v[i][j];
			int cnt=-1;
			vector<int> seq;
			do{
				if(a[u+1]<i){
					gg=true;
					break;
				}
				f[u]=u+1;
				cnt++;
				u=find(u);
				if(a[u]!=i) seq.push_back(a[u]); 
			}while(u!=v[i][j+1]);
			//for(auto x:seq) printf("%d ",x);
			//puts("");
			dp_reset(seq.size());
			ans=ans*solve(seq,0,seq.size())%Q;
		}
	}
	if(gg) puts("0");
	else printf("%lld\n",ans);
	return 0;
}