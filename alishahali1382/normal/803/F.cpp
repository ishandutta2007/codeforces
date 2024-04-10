#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long ll;
const int mod = 1000000007;
const int MAXN = 100010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
int M[MAXN];
int cnt[MAXN];
ll tav[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	M[1]=1;
	for (int i=1; i<MAXN; i++) for (int j=2*i; j<MAXN; j+=i) M[j]-=M[i];
	tav[1]=1;
	for (int i=2; i<MAXN; i++) tav[i]=(2*tav[i-1]+1)%mod;
	
	cin>>n;
	while (n--) cin>>x, cnt[x]++;
	for (int i=1; i<MAXN; i++){
		ll t=0;
		for (int j=i; j<MAXN; j+=i) t+=cnt[j];
		ans=(ans+M[i]*tav[t])%mod;
	}
	ans=(ans+mod)%mod;
	cout<<ans<<'\n';
	
	return 0;
}