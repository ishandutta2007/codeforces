#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") 
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
	int n, k;
	cin >> n >> k;
	pair<int,int>P[n];
	rep(i, n) {
		cin >> P[i].st;
		P[i].nd=i;
	}
	sort(P, P+n);
	int mi=1;
	rep(i, n-1) if(P[i].nd+1!=P[i+1].nd) ++mi;
	cout << (mi<=k?"Yes":"No") << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}