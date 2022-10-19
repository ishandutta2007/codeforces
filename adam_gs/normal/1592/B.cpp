#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
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
	int n, x;
	cin >> n >> x;
	int T[n];
	rep(i, n) cin >> T[i];
	if((n+1)/2-1>=x && n-(n+1)/2>=x) {
		cout << "YES\n";
		return;
	}
	vector<int>V;
	rep(i, n) if(n-1-i>=x || i>=x) V.pb(T[i]);
	sort(all(V));
	rep(i, V.size()/2) T[i]=V[i];
	reverse(all(V));
	rep(i, V.size()/2) T[n-i-1]=V[i];
	rep(i, n-1) if(T[i]>T[i+1]) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}