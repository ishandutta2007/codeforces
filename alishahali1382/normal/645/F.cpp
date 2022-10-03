#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long ll;
#define pb push_back
const int mod = 1000000007;
const int MAXN = 1000010;

ll powmod(ll a, ll b){
	if (!b) return 1;
	if (b&1) return a*powmod(a*a%mod, b>>1)%mod;
	return powmod(a*a%mod, b>>1);
}

ll n, q, k, u, v, x, y, t,ans;
vector<int> D[MAXN];
ll F[MAXN];
ll I[MAXN];
ll cnt[MAXN];
ll choose[MAXN];
int M[MAXN];

void add(int x){
	for (int d:D[x]) ans=(ans-M[d]*choose[cnt[d]]+M[d]*choose[++cnt[d]])%mod;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=1; i<MAXN; i++){
		M[i]+=i;
		for (int j=2*i; j<MAXN; j+=i) M[j]-=M[i];
	}
	
	F[0]=1;
	for (int i=1; i<MAXN; i++) F[i]=F[i-1]*i%mod;
	I[MAXN-1]=powmod(F[MAXN-1], mod-2);
	for (int i=MAXN-1; i; i--) I[i-1]=I[i]*i%mod;
	
	for (int i=1; i<MAXN; i++) for (int j=i; j<MAXN; j+=i) D[j].pb(i);
	
	cin>>n>>k>>q;
	for (ll i=k; i<MAXN; i++) choose[i]=(F[i]*I[k]%mod)*I[i-k]%mod;
	
	while (n--){
		cin>>x;
		add(x);
	}
	while (q--){
		cin>>x;
		add(x);
		if (ans<0) ans+=mod; 
		cout<<ans<<'\n';
	}
	
	return 0;
}