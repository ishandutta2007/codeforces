#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pr(a, b) make_pair(a, b)
#define pb(a) push_back(a)
typedef long long ll;
const int LIM=1e5+7;
const ll MOD=1e9+7;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, m, sa=0, sb=0, ma=0, mb=0;
		cin >> n;
		rep(i, n) {
			int a;
			cin >> a;
			sa+=a;
			ma=max(ma, sa);
		}
		cin >> m;
		rep(i, m) {
			int b;
			cin >> b;
			sb+=b;
			mb=max(mb, sb);
		}
		cout << ma+mb << '\n';
	}
}