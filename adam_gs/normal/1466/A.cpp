#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pr make_pair
#define pb push_back
#define st first
#define nd second
const int LIM=1e5+7;
const ll MOD=1e9+7;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int l[60], ans=0, n;
		rep(i, 60) l[i]=0;
		cin >> n;
		int T[n];
		rep(i, n) cin >> T[i];
		rep(i, n) for(int j=i+1; j<n; ++j) {
			if(!l[T[j]-T[i]]) ++ans;
			++l[T[j]-T[i]];
		}
		cout << ans << '\n';
	}
}