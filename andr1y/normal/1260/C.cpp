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
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 200000
#define INF 101111111111111
using namespace std;
int main(){
	FAST;
	ll q;
	cin >> q;
	while(q--){
		ll r, b, k;
		cin >> r >> b >> k;
		if(r > b) swap(r, b);
		ll ost0 = (b%r == 0 ? b/r : (b+r-1)/r);
		ll ostx = (b+r-1-__gcd(r, b))/r;
		if(ost0 > k || ostx >= k) cout << "REBEL";
		else cout << "OBEY";
		cout << endl;
	}
}