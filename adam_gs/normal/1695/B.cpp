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
	int n;
	cin >> n;
	int T[n];
	rep(i, n) cin >> T[i];
	if(n%2==1) {
		cout << "Mike\n";
		return;
	}
	pair<int,int>mi[2];
	mi[0]=mi[1]={INF, INF};
	rep(i, n) mi[i%2]=min(mi[i%2], {T[i], i});
	cout << (mi[0]<mi[1]?"Joe":"Mike") << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}