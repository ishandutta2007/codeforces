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
	int n;
	cin >> n;
	int A[n], B[n];
	rep(i, n) cin >> A[i];
	rep(i, n) cin >> B[i];
	sort(A, A+n);
	sort(B, B+n);
	rep(i, n) {
		if(A[i]>B[i] || A[i]+1<B[i]) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}