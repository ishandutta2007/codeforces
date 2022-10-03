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
#define SZ(x) ((int)x.size())
#define kill(x) return cout<<x<<'\n', 0;
#define getbit(x, y) (((x)>>(y))&1)

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=200010, K=100;

int n, q, k, u, v, x, y, p, a, b, ans;
int A[MAXN], B[MAXN];
ll sum[K][MAXN];
vector<int> D;
set<pair<ll, pii>> st;

void update(int i, int j, ll val){
	st.erase({sum[i][j]*D[i], {i, j}});
	sum[i][j]+=val;
	st.insert({sum[i][j]*D[i], {i, j}});
}

int Main(){
	st.clear();
	cin>>n>>q;
	for (int i=0; i<n; i++) cin>>A[i];
	for (int i=1; i<=n; i++) B[i]=0;
	for (int i=1; i<n; i++) B[n/__gcd(n, i)]=1;
	D.clear();
	for (int i=2; i<=n; i++) if (B[i]){
		D.pb(n/i);
		for (int j=i; j<=n; j+=i) B[j]=0;
	}
//	debugv(D)
	k=SZ(D);
	assert(k<100); // k < number of distinct prime divisors
	for (int i=0; i<k; i++){
		for (int j=0; j<D[i]; j++) sum[i][j]=0;
		for (int j=0; j<n; j++) sum[i][j%D[i]]+=A[j];
//		debug(sum[i][0])
		for (int j=0; j<D[i]; j++) st.insert({sum[i][j]*D[i], {i, j}});
	}
	cout<<(st.rbegin()->first)<<"\n";
	while (q--){
		cin>>p>>x;
		p--;
		for (int i=0; i<k; i++){
			update(i, p%D[i], x-A[p]);
		}
		A[p]=x;
		cout<<(st.rbegin()->first)<<"\n";
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while (T--) Main();
	
	return 0;
}