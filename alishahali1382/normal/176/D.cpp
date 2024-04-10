#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=2010, SGM=26;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN], T[MAXN], ps[MAXN];
int dp[MAXN][MAXN];
int nex[MAXN][SGM];
string B[MAXN], S;
vector<int> vec[MAXN][SGM];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>B[i];
		for (int j=0; j<B[i].size(); j++) vec[i][B[i][j]-'a'].pb(j);
	}
	cin>>m;
	for (int i=1; i<=m; i++) cin>>T[i], ps[i]=ps[i-1] + B[T[i]].size();
	for (int i=0; i<SGM; i++) nex[m+1][i]=m+1;
	for (int i=m; i; i--){
		for (int j=0; j<SGM; j++){
			if (vec[T[i]][j].empty()) nex[i][j]=nex[i+1][j];
			else nex[i][j]=i;
		}
	}
	cin>>S;
	n=S.size();
	for (ans=1; ans<MAXN; ans++){
		dp[ans][0]=ps[m]+1;
		for (int i=1; i<=n; i++){
			dp[ans][i]=dp[ans][i-1];
			int pos=dp[ans-1][i-1], c=S[i-1]-'a';
			if (pos>=ps[m]) continue ;
			int ind=upper_bound(ps+1, ps+m+1, pos)-ps;
			pos-=ps[ind-1];
			auto tmp=lower_bound(all(vec[T[ind]][c]), pos);
			if (tmp!=vec[T[ind]][c].end()) dp[ans][i]=min(dp[ans][i], ps[ind-1]+(*tmp)+1);
			else{
				ind=nex[ind+1][c];
				if (ind==m+1) continue ;
				dp[ans][i]=min(dp[ans][i], ps[ind-1]+vec[T[ind]][c][0]+1);
			}
		}
		if (dp[ans][n]>ps[m]) break ;
	}
	cout<<ans-1<<"\n";
	
	return 0;
}