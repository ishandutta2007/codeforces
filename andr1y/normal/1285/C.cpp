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

signed main(){
	FAST;
	ll x;
	cin >> x;
	ll mr = INF, mv = -1;
	bool alone = 0;
	for(ll i = 2;i*i<=x;i++){
		if(x%i == 0){
			if((i*(x/i))/__gcd(i, x/i) == x && max(i, x/i) < mr) mr = max(i, x/i), mv = min(i, x/i), alone = 1;
		}
	}
	if(!alone){
		mr = x, mv = 1;
	}
	cout << mr << " " << mv << endl;
}