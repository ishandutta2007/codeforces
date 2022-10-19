#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
void solve() {
	int n, l;
	cin >> n >> l;
	vector<int>T(l);
	rep(i, n) {
		int a;
		cin >> a;
		rep(j, l) if(a&(1<<j)) ++T[j];
	}
	int ans=0;
	rep(i, l) if(T[i]>=n-T[i]) ans+=1<<i;
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}