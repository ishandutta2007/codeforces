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
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=200010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans=1;
ll sieve[MAXN];
vector<int> vec[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=2; i<MAXN; i++) if (!sieve[i]) for (int j=i; j<MAXN; j+=i) sieve[j]=i;
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>x;
		while (x>1){
			int p=sieve[x], t=0;
			while (x%p==0) x/=p, t++;
			vec[p].pb(t);
		}
	}
	for (int i=2; i<MAXN; i++) if (sieve[i]==i){
		if (vec[i].size()>n-2){
			vec[i].resize(n, 0);
			sort(all(vec[i]));
			for (int j=0; j<vec[i][1]; j++) ans=ans*i;
		}
	}
	cout<<ans<<'\n';
	
	return 0;
}