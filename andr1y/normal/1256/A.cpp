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
		ll a, b, n, s;
		cin >> a >> b >> n >> s;
		ll mga = (s-min(s/n, a)*n);
		if(mga <= b) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}