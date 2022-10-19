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
	int T[n+1][m+1], mi[n+1][m+1], ma[n+1][m+1];
	rep(i, n+1) rep(j, m+1) T[i][j]=mi[i][j]=ma[i][j]=0;
	rep(i, n-1) {
		mi[i+2][0]=INF;
		ma[i+2][0]=-INF;
	}
	rep(i, m-1) {
		mi[0][i+2]=INF;
		ma[0][i+2]=-INF;
	}
	rep(i, n) rep(j, m) {
		cin >> T[i+1][j+1];
		mi[i+1][j+1]=min(mi[i][j+1], mi[i+1][j])+T[i+1][j+1];
		ma[i+1][j+1]=max(ma[i][j+1], ma[i+1][j])+T[i+1][j+1];
	}
	if((n+m-1)%2==1) {
		cout << "NO\n";
		return;
	}
	cout << (mi[n][m]<=0 && 0<=ma[n][m] ? "YES" : "NO") << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}