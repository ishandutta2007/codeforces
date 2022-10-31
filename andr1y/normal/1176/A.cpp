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
		ll n;
		cin >> n;
		ll r = 0;
		while(n%2==0) ++r, n/=2;
		while(n%3==0) ++r, n*=2, n/=3;
		while(n%2==0) ++r, n/=2;
		while(n%5==0) ++r, n*=4, n/=5;
		while(n%2==0) ++r, n/=2;
		if(n==1) cout << r << endl;
		else cout << -1 << endl;
	}
}