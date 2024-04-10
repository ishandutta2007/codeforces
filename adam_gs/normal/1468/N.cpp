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
		int T[3];
		rep(i, 3) cin >> T[i];
		rep(i, 3) {
			int a;
			cin >> a;
			T[i]-=a;
		}
		int a, b;
		cin >> a >> b;
		if(min(T[0], min(T[1], T[2]))<0) {
			cout << "NO\n";
			continue;
		}
		if(a>T[0]) {
			a-=T[0];
			T[2]-=a;
		}
		if(b>T[1]) {
			b-=T[1];
			T[2]-=b;
		}
		cout << (T[2]>=0?"YES":"NO") << '\n';
	}
}