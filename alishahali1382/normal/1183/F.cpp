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
const int MAXN = 200010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b;
int A[MAXN];

int solve(){
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	sort(A, A+n+1);
	n=unique(A, A+n+1)-A-1;
	vector<int> vec;
	int out=0, tof=0;
	
	for (; n; n--){
		vector<int> vec;
		int ans=0;
		for (int i=n; i; i--){
			bool f=1;
			for (int x:vec) if (x%A[i]==0) f=0;
			if (!f) continue ;
			vec.pb(A[i]);
			ans+=A[i];
			if (vec.size()==3) break ;
		}
		out=max(out, ans);
		if (n>=2 && A[n]+A[n-1]+A[n-2]<=out) break ;
	}
	
	kill(out)
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	cin>>T;
	while (T--) solve();
	
	return 0;
}