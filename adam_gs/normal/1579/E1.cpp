#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
void solve() {
	int n;
	cin >> n;
	int T[n];
	rep(i, n) cin >> T[i];
	deque<int>q;
	q.push_front(T[0]);
	for(int i=1; i<n; ++i) {
		if(T[i]<q.front()) q.push_front(T[i]);
		else q.push_back(T[i]);
	}
	while(!q.empty()) {
		cout << q.front() << " ";
		q.pop_front();
	}
	cout << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}