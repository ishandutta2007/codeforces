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
const int MAXN = 300010, K=8;

ll n, m, k, u, v, x, y, t, a, b, ans;
int cnt[MAXN];
ll val[MAXN];
ll C[MAXN][K];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	C[0][0]=1;
	for (int i=1; i<MAXN; i++){
		C[i][0]=1;
		for (int j=1; j<K; j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	cin>>n;
	while (n--){
		cin>>x;
		cnt[x]++;
	}
	for (int i=1; i<MAXN; i++) for (int j=i+i; j<MAXN; j+=i) cnt[i]+=cnt[j];
	for (ans=1; ans<K; ans++){
		for (int i=1; i<MAXN; i++) val[i]=C[cnt[i]][ans];
		for (int i=MAXN-1; i; i--) for (int j=i+i; j<MAXN; j+=i) val[i]-=val[j];
		if (val[1]%mod) kill(ans)
	}
	kill(-1)
	
	return 0;
}