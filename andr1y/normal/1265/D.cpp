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
#define N 1000105
#define INF 101111111111111
using namespace std;
ll a[4];
void check(ll f){
	ll b[4];
	for(ll i =0;i<4;i++) b[i] = a[i];
	if(b[f] == 0) return;
	b[f]--;
	vector<ll> r;
	r.pb(f);
	while(b[0] > 0 || b[1] > 0 || b[2] > 0 || b[3] > 0){
		bool ok=0;
		if((r.back() == 1) && b[0] > 0){
			r.pb(0);
			b[0]--; ok=1;
		}
		if((r.back() == 0 || r.back() == 2) && b[1] > 0){
			r.pb(1);
			b[1]--; ok=1;
		}
		if((r.back() == 1 || r.back() == 3) && b[2] > 0){
			r.pb(2);
			b[2]--; ok=1;
		}
		if((r.back() == 2) && b[3] > 0){
			r.pb(3);
			b[3]--; ok=1;
		}
		if(!ok) return;
	}
	cout <<"YES" << endl;
	for(auto i : r)cout << i << " ";
	cout << endl;
	exit(0);
}
int main(){
	FAST;
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	check(0);
	check(1);
	check(2);
	check(3);
	cout << "NO" << endl;
}