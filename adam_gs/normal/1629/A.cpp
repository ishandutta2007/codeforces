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
	int n, k;
	cin >> n >> k;
	pair<int,int>T[n];
	rep(i, n) cin >> T[i].st;
	rep(i, n) cin >> T[i].nd;
	sort(T, T+n);
	rep(i, n) if(T[i].st<=k) k+=T[i].nd;
	cout << k << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}