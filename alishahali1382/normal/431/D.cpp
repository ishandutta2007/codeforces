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
const int MAXN = 100010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll C[70][70];

ll f(ll num, int k){
	if (!k) return 1;
	if (!num || k<0) return 0;
	int pos=63-__builtin_clzll(num);
	return C[pos][k] + f(num^(1ll<<pos), k-1);
}

ll get(ll x){
	return f(2*x, k)-f(x, k);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	C[0][0]=1;
	for (int i=1; i<62; i++){
		C[i][0]=1;
		for (int j=1; j<=i; j++) C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
	cin>>m>>k;
	ll dwn=0, up=1e18+10;
	while (up-dwn>1){
		ll mid=(dwn+up)/2;
		if (get(mid)<m) dwn=mid;
		else up=mid;
	}
	kill(up)
	
	return 0;
}