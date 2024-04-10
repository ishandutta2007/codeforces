#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'

#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

#ifndef __LOCAL
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout); FAST;
#else
#define FILES(namein, nameout) FAST;
#endif //__LOCAL

using namespace std;
using namespace __gnu_pbds;
using python = void;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned short uss;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type> ordered_set;

const ll M = 1e9+7;
const ll N = 228;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;
bool a[N][N];

bool c1(ll &n, ll &m){
	bool al1 = 1, al2 = 1;
	for(ll i =0;i<m;i++){
		al1 = al1&(a[0][i]);
		al2 = al2&(a[n-1][i]);
	}
	if(al1 || al2) return 1;
	al1 = 1, al2 = 1;
	for(ll i =0;i<n;i++){
		al1 = al1&(a[i][0]);
		al2 = al2&(a[i][m-1]);
	}
	return (al1||al2);
}

bool c2(ll &n, ll &m){
	vector<bool> ak(n, 1);
	vector<bool> ae(m, 1);
	bool alone = 0;
	for(ll i =0;i<n;i++){
		for(ll j= 0;j<m;j++){
			ak[i] = ak[i]&a[i][j];
			ae[j] = ae[j]&a[i][j];
			if(i == n-1) alone |= ae[j];
		}
		alone |= ak[i];
	}
	return (a[0][0] || a[0][m-1] || a[n-1][0] || a[n-1][m-1] || alone);
}

bool c3(ll &n, ll &m){
	bool alone = 0;
	for(ll i =0;i<n;i++) alone |= a[i][0] | a[i][m-1];
	for(ll i =0;i<m;i++) alone |= a[0][i] | a[n-1][i];
	return alone;
}

python solve(){
	FAST;
	ll n, m;
	char c;
	cin >> n >> m;
	bool alone = 0, al2 = 0;
	for(ll i =0;i<n;i++){
		for(ll j =0;j<m;j++){
			cin >> c;
			if(c == 'A') a[i][j] = 1, alone = 1;
			else a[i][j] = 0, al2 = 1;
		}
	}
	if(!alone){
		cout << "MORTAL\x0a";
		return;
	}
	if(!al2){
		cout << "0\x0a";
		return;
	}
	if(c1(n, m)) cout << "1\x0a";
	else if(c2(n, m)) cout << "2\x0a";
	else if(c3(n, m)) cout << "3\x0a";
	else cout << "4\x0a";
}

signed main(){
	FAST;
	ll q = 1;
	cin >> q;
	while(q--){
		solve();
	}
}