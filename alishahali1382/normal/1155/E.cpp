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
const ll mod = 1000003;
const int MAXN = 110, LOG=20;

ll powmod(ll a, ll b){
	if (!b) return 1;
	if (b&1) return a*powmod(a*a%mod, b>>1)%mod;
	return powmod(a*a%mod, b>>1);
}

ll inv(ll x){ return (mod+powmod((mod+x)%mod, mod-2))%mod;}

ll n=11, m, k, u, v, x, y, tmp, s;
ll AA[MAXN];
ll A[MAXN][MAXN];

ll ask(ll x){
	cout<<"? "<<x<<endl;
	cout.flush();
	cin>>tmp;
	if (!tmp){
		cout<<"! "<<x<<endl;
		cout.flush();
		exit(0);
	}
	
	return tmp;
}

ll f(ll x){
	ll res=0;
	for (ll i=0; i<=10; i++) res=(res+AA[i]*powmod(x, i))%mod;
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
    // Read input data
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            A[i][j]=powmod(i, j);
        }
        A[i][0]=1;
    }

    for (int i=0; i<n; i++) {
        A[i][n]=ask(i);
    }

	for (int i=0; i<n; i++){
		for (int j=i+1; j<n; j++){
			ll tmp=-A[j][i]*inv(A[i][i])%mod;
			for (int k=0; k<=n; k++) A[j][k]=(A[j][k]+A[i][k]*tmp)%mod;
		}
	}
	for (int i=n-1; i>=0; i--){
		AA[i]=A[i][n]*inv(A[i][i])%mod;
		for (int j=i-1; j>=0; j--) A[j][n]=(A[j][n]-A[j][i]*AA[i])%mod;
	}

	for (int i=0; i<mod; i++) if (!f(i)){
		cout<<"! "<<i<<endl;
		cout.flush();
		return 0;
	}
	cout<<"! -1"<<endl;
	cout.flush();
	
	//for (int i=0; i<11; i++) debug2(i, AA[i])
	
	return 0;
}
/*
      ___           ___                            ___           ___           ___           ___           ___           ___
     /\  \         /\__\      ___                 /\  \         /\__\         /\  \         /\__\         /\  \         /\__\      ___
    /::\  \       /:/  /     /\  \               /::\  \       /:/  /        /::\  \       /:/  /        /::\  \       /:/  /     /\  \
   /:/\:\  \     /:/  /      \:\  \             /:/\ \  \     /:/__/        /:/\:\  \     /:/__/        /:/\:\  \     /:/  /      \:\  \
  /::\~\:\  \   /:/  /       /::\__\           _\:\~\ \  \   /::\  \ ___   /::\~\:\  \   /::\  \ ___   /::\~\:\  \   /:/  /       /::\__\
 /:/\:\ \:\__\ /:/__/     __/:/\/__/          /\ \:\ \ \__\ /:/\:\  /\__\ /:/\:\ \:\__\ /:/\:\  /\__\ /:/\:\ \:\__\ /:/__/     __/:/\/__/
 \/__\:\/:/  / \:\  \    /\/:/  /             \:\ \:\ \/__/ \/__\:\/:/  / \/__\:\/:/  / \/__\:\/:/  / \/__\:\/:/  / \:\  \    /\/:/  /
      \::/  /   \:\  \   \::/__/               \:\ \:\__\        \::/  /       \::/  /       \::/  /       \::/  /   \:\  \   \::/__/
      /:/  /     \:\  \   \:\__\                \:\/:/  /        /:/  /        /:/  /        /:/  /        /:/  /     \:\  \   \:\__\
     /:/  /       \:\__\   \/__/                 \::/  /        /:/  /        /:/  /        /:/  /        /:/  /       \:\__\   \/__/
     \/__/         \/__/                          \/__/         \/__/         \/__/         \/__/         \/__/         \/__/
*/