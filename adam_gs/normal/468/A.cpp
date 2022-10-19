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
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	if(n<4) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	if(n==5) {
		cout << "5 - 3 = 2\n1 + 2 = 3\n2 * 4 = 8\n3 * 8 = 24\n";
		return 0;
	} 
	if(n!=4) {
		cout << n << " - " << n-1 << " = 1\n";
		cout << "1 - 1 = 0" << '\n';
		for(int i=5; i<n-1; ++i) cout << "0 * " << i << " = 0\n";
		cout << "0 + 2 = 2\n";
	} else {
		cout << "1 * 2 = 2\n";
	}
	cout << "2 * 3 = 6\n6 * 4 = 24\n";
}