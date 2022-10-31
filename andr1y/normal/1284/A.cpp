#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#ifndef __LOCAL
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#else
#define FILES(namein, nameout) FAST;
#endif //__LOCAL
#define M 1000000007
#define N 200200
#define INF 101111111111111LL
using namespace std;
using python = void;

string a[N], b[N];
signed main(){
	FAST;
	ll n, m;
	cin >> n >> m;
	for(ll i = 0;i<n;i++) cin >> a[i];
	for(ll j = 0;j<m;j++) cin >> b[j];
	ll q;
	cin >> q;
	while(q--){
		ll y;
		cin >> y;
		y--;
		cout << a[y%n] << b[y%m] << endl;
	}
}