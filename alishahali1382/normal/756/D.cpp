#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
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
const int MAXN = 100010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll F[MAXN];
ll I[MAXN];
ll dp[MAXN][26];
char ch[MAXN];

ll C(ll n, ll r){
	if (r<0 || r>n) return 0;
	return (F[n]*I[r]%mod)*I[n-r]%mod;
}

ll powmod(ll a, ll b){
	if (!b) return 1;
	if (b&1) return a*powmod(a*a%mod, b>>1)%mod;
	return powmod(a*a%mod, b>>1);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	F[0]=1;
	for (int i=1; i<MAXN; i++) F[i]=F[i-1]*i%mod;
	I[MAXN-1]=powmod(F[MAXN-1], mod-2);
	for (int i=MAXN-1; i; i--) I[i-1]=I[i]*i%mod;
	
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>ch[i];
		if (ch[i-1]!=ch[i]){
			dp[1][ch[i]-'a']=1;
			for (int len=2; len<=i; len++){
				dp[len][ch[i]-'a']=0;
				for (int c=0; c<26; c++) if (c!=(ch[i]-'a')) dp[len][ch[i]-'a']+=dp[len-1][c];
				dp[len][ch[i]-'a']%=mod;
			}
		}
	}
	for (int len=1; len<=n; len++){
		ll val=0;
		for (int i=0; i<26; i++) val+=dp[len][i];
		val%=mod;
		ans+=C(n-1, len-1)*val%mod;
	}
	ans%=mod;
	cout<<ans<<'\n';
	
	return 0;
}