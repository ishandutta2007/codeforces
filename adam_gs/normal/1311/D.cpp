#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
const int LIM=2*10000;
vector<int>a, b, c;
void solve() {
	int x, y, z;
	cin >> x >> y >> z;
	int ans=LIM, d=-1, e=-1, f=-1;
	rep(i, a.size()) {
		int p=abs(x-a[i])+abs(y-b[i])+abs(z-c[i]);
		if(ans>p) {
			ans=p;
			d=a[i];
			e=b[i];
			f=c[i];
		}
	}
	cout << ans << '\n' << d << " " << e << " " << f << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for(int i=1; i<=LIM; ++i) {
		for(int j=i; j<=LIM; j+=i) {
			for(int l=j; l<=LIM; l+=j) {
				a.pb(i);
				b.pb(j);
				c.pb(l);
			}
		}
	}
	int _=1;
	cin >> _;
	while(_--) solve();
}