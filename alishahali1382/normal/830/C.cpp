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
const int MAXN = 110;

ll n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
vector<int> D;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		k+=A[i];
		for (ll j=1; j*j<=A[i]; j++){
			D.pb(j);
			D.pb((A[i]+j-1)/j);
		}
	}
	sort(all(D));
	D.resize(unique(all(D))-D.begin());
	for (ll dd:D){
		ll tmp=0;
		for (int i=1; i<=n; i++) tmp+=(A[i]+dd-1)/dd;
		ll d=k/tmp;
		if (dd<=d) ans=max(ans, d);
	}
	cout<<ans<<'\n';
	
	return 0;
}