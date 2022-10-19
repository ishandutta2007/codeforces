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
	int a, b;
	cin >> a >> b;
	if((a+b)%2==1) {
		cout << "-1 -1\n";
		return;
	}
	int d=(a+b)/2;
	if(d>a) {
		cout << a << " " << d-a << '\n';
	} else {
		cout << d << " " << 0 << '\n';
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}