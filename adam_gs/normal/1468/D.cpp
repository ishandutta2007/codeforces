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
		int n, m, a, b, o, p;
		cin >> n >> m >> a >> b;
		o=abs(a-b)-1;
		if(a<b) {
			p=b-1;
		} else {
			p=n-b;
		}
		int T[m];
		rep(i, m) {cin >> T[i]; ++T[i];}
		sort(T, T+m);
		--m;
		int ans=0;
		while(o) {
			while(m>=0 && T[m]>p) --m;
			if(m<0) break;
			--m;
			--p;
			--o;
			++ans;
		}
		cout << ans << '\n';
	}
}