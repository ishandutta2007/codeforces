#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector<pair<int,int>>V;
	int x=-100000000, y=1;
	for(int i=1; i<=150; ++i) {
		V.pb({x, y});
		y+=i;
		x+=300-i;
	}
	int n, m;
	cin >> n >> m;
	if(m==3 && n>4) {
		cout << -1 << '\n';
		return 0;
	}
	rep(i, m) cout << V[i].st << " " << V[i].nd << '\n';
	rep(i, n-m) cout << -V[i].st << " " << -V[i].nd << '\n';
}