#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const ll INF=1e18+7;
const int LIM=80;
ll dp[LIM][LIM], lst[LIM][LIM];
pair<pair<ll,ll>,ll>T[LIM];
void solve() {
	ll n, k;
	cin >> n >> k;
	rep(i, n+2) rep(j, n+2) dp[i][j]=lst[i][j]=0;
	rep(i, n) {
		cin >> T[i].st.nd >> T[i].st.st;
		T[i].nd=i;
	}
	sort(T, T+n);
	rep(j, k) dp[0][j+1]=-INF;
	rep(i, n) rep(j, k+1) {
		dp[i+1][j]=dp[i][j]+T[i].st.st*(k-1);
		if(j && dp[i][j-1]+T[i].st.nd+T[i].st.st*(j-1)>dp[i+1][j]) {
			dp[i+1][j]=dp[i][j-1]+T[i].st.nd+T[i].st.st*(j-1);
			lst[i+1][j]=1;
		}
	}
	vector<ll>A, B;
	for(ll i=n; i; --i) {
		if(lst[i][k]==1) {
			A.pb(T[i-1].nd);
			--k;
		} else B.pb(T[i-1].nd);
	}
	reverse(all(A));
	reverse(all(B));
	cout << A.size()+2*B.size() << '\n';
	rep(i, A.size()-1) cout << A[i]+1 << " ";
	for(auto i : B) cout << i+1 << " " << -i-1 << " ";
	cout << A.back()+1 << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}