#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int INF=1e9+7;
void solve() {
	int n, m;
	cin >> n >> m;
	int T[n][m], ma=-INF, a=-1, b=-1;
	rep(i, n) rep(j, m) {
		cin >> T[i][j];
		if(T[i][j]>ma) {
			ma=T[i][j];
			a=i; b=j;
		}
	}
	cout << max(a+1, n-a)*max(b+1, m-b) << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}