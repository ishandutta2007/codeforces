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
ll bp(ll a, ll b){
	if(b == 0) return 1;
	else if(b == 1) return a;
	else if(b&1) return a*bp(a*a, b/2);
	else return bp(a*a, b/2);
}
int main(){
	FAST;
	ll q;
	cin >> q;
	while(q--){
		ll n, s;
		cin >> n >> s;
		ll h = s/n;
		ll last = s-h*n;
		if(last == 0){
			cout << bp(h, 2)*n << endl;
		}else{
			ll ns = last/n;
			ll need = last% n;
			cout << bp(h+ns, 2)*(n-need) + bp(h+ns+1, 2)*(need) << endl;
		}
	}
}