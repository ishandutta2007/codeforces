#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 3010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
ll dp[MAXN][MAXN];
int TR[MAXN*MAXN][3], ts;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int r=1; r<=n; r++) for (int l=n+1; l; l--){
		if (l>r){
			dp[l][r]=1;
			continue ;
		}
		for (int i=1; i<=4 && l+i-1<=r; i++){
			if (i==4){
				string s="";
				s+=A[l]+'0';
				s+=A[l+1]+'0';
				s+=A[l+2]+'0';
				s+=A[l+3]+'0';
				if (s=="0011" || s=="0101" || s=="1110" || s=="1111") continue ;
			}
			dp[l][r]+=dp[l+i][r];
		}
		dp[l][r]%=mod;
	}
	
	for (int i=1; i<=n; i++){
		int node=0;
		for (int j=i; j; j--){
			if (!TR[node][A[j]]) TR[node][A[j]]=++ts;
			node=TR[node][A[j]];
			if (TR[node][2]) continue ;
			TR[node][2]=1;
			ans=(ans+dp[j][i])%mod;
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
/*
3
1 1 1

*/