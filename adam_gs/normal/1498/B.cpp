#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") 
#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
void solve() {
	int n, w;
	cin >> n >> w;
	int T[n];
	rep(i, n) cin >> T[i];
	sort(T, T+n);
	reverse(T, T+n);
	priority_queue<int>q;
	int ans=1;
	q.push(w);
	rep(i, n) {
		int p=q.top(); q.pop();
		if(p<T[i]) {
			q.push(w-T[i]);
			++ans;
		} else p-=T[i];
		q.push(p);
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}