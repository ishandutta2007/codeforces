#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define lg(a) (31-__builtin_clz(a))
#define all(a) a.begin(), a.end()
void solve() {
	int n;
	cin >> n;
	bool ans=false;
	rep(i, n) {
		int a;
		cin >> a;
		int p=sqrt(a);
		if(p*p!=a) ans=true;
	}
	cout << (ans?"YES":"NO") << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t=1;
	cin >> t;
	while(t--) solve();
}