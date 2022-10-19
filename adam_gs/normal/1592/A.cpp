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
	int n, h;
	cin >> n >> h;
	int T[n];
	rep(i, n) cin >> T[i];
	sort(T, T+n);
	reverse(T, T+n);
	int p=h/(T[0]+T[1]);
	h-=p*(T[0]+T[1]);
	p*=2;
	if(h==0);
	else if(h<=T[0]) ++p;
	else p+=2;
	cout << p << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}