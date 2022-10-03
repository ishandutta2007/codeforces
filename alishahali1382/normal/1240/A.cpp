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
const int MAXN = 200010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll A[MAXN];
ll B[MAXN];
vector<int> vec;

ll get(int m){
	vec.clear();
	for (int i=1; i<=m; i++) vec.pb(B[i]);
	sort(all(vec));
	reverse(all(vec));
	ll res=0;
	for (int i=0; i<m; i++) res+=vec[i]*A[i+1];
	return res;
}

void solve(){
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		A[i]/=100;
		B[i]=0;
	}
	sort(A+1, A+n+1);
	reverse(A+1, A+n+1);
	cin>>x>>a;
	for (int i=a; i<=n; i+=a) B[i]+=x;
	cin>>y>>b;
	for (int i=b; i<=n; i+=b) B[i]+=y;
	cin>>k;
	int dwn=0, up=n+1;
	while (up-dwn>1){
		int mid=(dwn+up)/2;
		if (get(mid)>=k) up=mid;
		else dwn=mid;
	}
	if (up==n+1) up=-1;
	cout<<up<<'\n';
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;cin>>T;
	while (T--) solve();
	
	return 0;
}