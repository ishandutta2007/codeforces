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
#define N 252252
#define INF 101111111111111LL
using namespace std;
using python = void;

ll f[N];
ll ak[N];

signed main(){
	FAST;
	ll n, m;
	cin >> n >> m;
	ll res = 0;
	f[0] = 1;
	f[1] = 1;
	f[2] = 2;
	for(ll i =3;i<=n+100;i++) f[i] = (f[i-1]*i)%m;
	for(ll i = 1;i<=n;i++){
		res = (res + (((f[n-i+1]*f[i])%m)*(n-i+1))%m)%m;
	}
	cout << res << endl;
}