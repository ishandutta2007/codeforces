#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define lg(a) (31-__builtin_clz(a))
#define all(a) a.begin(), a.end()
ll pow(ll a,ll b,ll c){ll w=1;while(b){if(b&1)w=(w*a)%c;b/=2;a=(a*a)%c;}return w;}
const int LIM=507;
int T[LIM][LIM], a[LIM], n, p, l;
void DFS(int a, int b) {
	T[a][b]=l;
	--p;
	if(p && b && !T[a][b-1]) {
		DFS(a, b-1);
	}
	if(p && a<n-1 && !T[a+1][b]) {
		DFS(a+1, b);
	}
}
void solve() {
	cin >> n;
	rep(i, n) {
		cin >> p;
		l=p;
		DFS(i, i);
	}
	rep(i, n) {
		rep(j, i+1) cout << T[i][j] << " ";
		cout << '\n';
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t=1;
	while(t--) solve();
}