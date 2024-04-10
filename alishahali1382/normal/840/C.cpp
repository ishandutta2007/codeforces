#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long ll;

const int mod = 1000000007;
const int MAXN = 310;

ll F[1010];
ll I[1010];
ll powmod(ll a, ll b){
	if (!b) return 1;
	if (b&1) return a*powmod(a, b-1)%mod;
	return powmod(a*a%mod, b>>1);
}
ll C(ll n, ll r){
	if (r<0 || r>n || n<0) return 0;
	return (F[n]*I[r]%mod)*I[n-r]%mod;
}

ll calc(ll len, ll size, ll bad, ll a, ll b){
	ll res=F[size]*C(size-1, a-1)%mod;
	res=res*C(bad, b)%mod;
	res=res*C(len-bad+1, a-b)%mod;
	return res;
}

ll n, m, k, u, v, x, y, t, a, b, len;
ll cnt[MAXN];
ll dp[MAXN][MAXN];
unordered_map<int, int> mp;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	F[0]=I[0]=1;
	for (int i=1; i<1010; i++){
		F[i]=(F[i-1]*i)%mod;
		I[i]=(I[i-1]*powmod(i, mod-2))%mod;
	}
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>x;
		for (ll j=2; j*j<=x; j++) while (x%(j*j)==0) x/=j*j;
		mp[x]++;
	}
	for (auto p:mp) cnt[t++]=p.second;
	
	dp[0][0]=1;
	for (int i=0; i<t; i++){
		for (int j=0; j<=n; j++) for (ll a=1; a<=cnt[i]; a++) for (ll b=0; b<=a; b++) dp[i+1][j+cnt[i]-a-b]=(dp[i+1][j+cnt[i]-a-b]+dp[i][j]*calc(len, cnt[i], j, a, b))%mod;
		len+=cnt[i];
	}
	cout<<dp[t][0]<<endl;
	
	return 0;
}