#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
#define lg(a) (31-__builtin_clz(a))
const int LIM=5007;
int T[LIM], pi[LIM], os[LIM];
void solve() {
	int n;
	cin >> n;
	rep(i, LIM) pi[i]=os[i]=-1;
	rep(i, n) cin >> T[i];
	rep(i, n) {
		os[T[i]]=i;
		if(pi[T[i]]==-1) pi[T[i]]=i;
	}
	rep(i, LIM) {
		if(pi[i]+1<os[i]) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}