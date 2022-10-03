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

ll n, m, k, u, v, x, y, t;
ll X[MAXN], Y[MAXN];
ll Z[MAXN];
vector<int> out;

ll get(ll x, ll y){
	return x*x+y*y;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	if (n==2){
		cout<<"1\n1\n";
		return 0;
	}
	for (int i=1; i<=n; i++) cin>>X[i]>>Y[i], Z[i]=X[i]+Y[i];
	while (1){
		bool f0=0, f1=0;
		for (int i=1; i<=n; i++){
			ll tmp=Z[i];
			if (tmp&1) f1=1;
			else f0=1;
		}
		if (f0 && f1){
			for (int i=1; i<=n; i++) if (Z[i]&1) out.pb(i);
			cout<<out.size()<<'\n';
			for (int i:out) cout<<i<<' ';
			return 0;
		}
		if (!f0) for (int i=1; i<=n; i++) Z[i]--, Y[i]--;
		else{
			// hame x+y zoj
			f0=f1=0;
			for (int i=1; i<=n; i++){
				if (X[i]&1) f1=1;
				else f0=1;
			}
			if (f0 && f1) break ;
			if (f0){
				// hame x zoj
				for (int i=1; i<=n; i++){
					X[i]/=2;
					Y[i]/=2;
					Z[i]/=2;
				}
			}
			else{
				// hame x fard
				for (int i=1; i<=n; i++){
					X[i]--;
					Y[i]++;
					X[i]/=2;
					Y[i]/=2;
					Z[i]/=2;
				}
			}
		}
	}
	for (int i=1; i<=n; i++) if (X[i]&1) out.pb(i);
	cout<<out.size()<<'\n';
	for (int i:out) cout<<i<<' ';
	
	return 0;
}