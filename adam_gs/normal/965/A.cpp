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
	ll k, n, s, p;
	cin >> k >> n >> s >> p;
	ll x=(n+s-1)/s; x*=k;
	ll y=(x+p-1)/p;
	cout << y << '\n';
}