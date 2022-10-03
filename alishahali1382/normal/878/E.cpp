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
const int MAXN=100010, LOG=19;

ll n, m, k, u, v, l, r, t, a, b, ans;
ll A[MAXN];
ll H[MAXN], tav[MAXN], inv[MAXN];
ll val[MAXN];
int F[MAXN];
int par[LOG][MAXN];
ll S[LOG][MAXN];

pll calc(int i, ll val){ // kmp?!
	if (F[i]==-1 || i-F[i]>=31 || val>=1000000000)
		return {-1, 0};
	
	for (int j=i; j>F[i]; j--) val=(A[j] + 2*val);
	if (val>=1000000000) return {-1, 0};
	if (val<=0) return {F[i], val};
	return calc(F[i], val);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	tav[0]=inv[0]=1;
	for (int i=1; i<MAXN; i++) tav[i]=tav[i-1]*2%mod;
	inv[1]=(mod+1)/2;
	for (int i=2; i<MAXN; i++) inv[i]=inv[i-1]*inv[1]%mod;
	
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>A[i], H[i]=(H[i-1] + A[i]*tav[i])%mod;
	F[0]=-1;
	for (int i=1; i<=n; i++){
		if (A[i]<=0){
			F[i]=i-1;
			val[i]=A[i];
			continue ;
		}
		pll tmp=calc(i-1, A[i]);
		F[i]=tmp.first;
		val[i]=tmp.second;
	}
	for (int i=1; i<=n; i++){
		par[0][i]=max(0, F[i]);
		S[0][i]=val[i];
	}
	for (int j=1; j<LOG; j++) for (int i=1; i<=n; i++){
		par[j][i]=par[j-1][par[j-1][i]];
		S[j][i]=S[j-1][i] + S[j-1][par[j-1][i]];
	}
	/*
	debug2(F[4], val[4])
	debug2(F[3], val[3])
	debug2(F[2], val[2])
	debug2(F[1], val[1])
	*/
	while (m--){
		cin>>l>>r;
		ans=0;
		ll sum=0;
		/*
		while (l<=r && l<=F[r]){
			ans+=2*val[r];
			r=F[r];
		}
		*/
		
		for (int i=LOG-1; ~i; i--) if (l<=par[i][r]){
			ans+=2*S[i][r];
			r=par[i][r];
		}
		while (l<=r && sum<1000000000){
			sum=(A[r--] + 2*sum);
			if (sum<0){
				if (l<=r) ans+=2*sum;
				else ans+=sum;
				sum=0;
			}
		}
		ans=(ans + sum*tav[r-l+1])%mod;
		ans=(ans + (H[r]-H[l-1])*inv[l])%mod;
		if (ans<0) ans+=mod;
		cout<<ans<<"\n";
	}
	
	
	return 0;
}
/*
5 10
1 -1 3 -4 5
1 2
1 3
1 4
1 5
2 3
2 4
2 5
3 3
3 4
3 5
4 5


ans:
1000000006
11
3
59
5
1000000004
29
3
1000000002
15

*/