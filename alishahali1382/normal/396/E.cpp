#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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

const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=1000010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
int sieve[MAXN];
ll A[MAXN], B[MAXN];
vector<pll> vec[MAXN];

void add(ll x, ll l, ll r){
//	cerr<<"add: "<<x<<" : "<<l<<", "<<r<<"\n";
	x--;
	for (; x>1; x/=sieve[x]){
		ll p=sieve[x];
		if (k<=l) A[p]+=r-l;
		else if (r<=k) vec[p].pb({l, r});
		else{
			vec[p].pb({l, k});
			A[p]+=r-k;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=2; i<MAXN; i++) if (!sieve[i]) for (int j=i; j<MAXN; j+=i) sieve[j]=i;
	cin>>n;
	while (n--) cin>>x>>y, B[x]=y;
	cin>>k;
	for (int i=1; i<MAXN; i++) if (B[i]){
		if (B[i]<=k) vec[i].pb({0, B[i]});
		else{
			A[i]+=B[i]-k;
			vec[i].pb({0, k});
		}
	} 
	for (int i=MAXN-1; i>1; i--) if (vec[i].size()){
		sort(all(vec[i]));
		for (int j=1; j<vec[i].size(); j++) if (vec[i][j].first<vec[i][j-1].second){
			ll x=vec[i][j-1].second-vec[i][j].first;
			vec[i][j-1].second=vec[i][j].first;
			vec[i][j].second+=x;
		}
		for (pll p:vec[i]){
			ll l=p.first, r=p.second;
			if (r<=k) add(i, l+1, r+1);
			else if (k<=l) A[i]+=r-l;
			else{
				add(i, l+1, k+1);
				A[i]+=r-k;
			}
		}
	}
	for (int i=2; i<MAXN; i++) ans+=(A[i]>0);
	cout<<ans<<"\n";
	for (int i=2; i<MAXN; i++) if (A[i]>0) cout<<i<<" "<<A[i]<<"\n";
	
	return 0;
}