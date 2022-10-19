#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define lg(a) (31-__builtin_clz(a))
const int LIM=1e5+7, MOD=1e9+7;
void solve() {
	int n;
	cin >> n;
	int T[n];
	rep(i, n) cin >> T[i];
	sort(T, T+n);
	int ans=0;
	rep(i, n) if(T[i]!=T[0]) ++ans;
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	//t=1;
	while(t--) solve();
}