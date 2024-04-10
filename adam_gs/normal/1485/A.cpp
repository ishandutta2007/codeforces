#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define lg(a) (31-__builtin_clz(a))
const int LIM=1e5+7, MOD=1e9+7;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int a, b;
		cin >> a >> b;
		int ans=MOD;
		for(int i=0; i<30; ++i) {
			if(b+i<2) continue;
			int l=i, p=a;
			while(p) {
				p/=(b+i);
				++l;
			}
			ans=min(ans, l);
		}
		cout << ans << '\n';
	}
}