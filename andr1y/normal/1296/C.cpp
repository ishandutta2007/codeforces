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
const ll N = 2e5+228;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;
map<pll, ll> a;
python solve(){
	FAST;
	ll n;
	cin >> n;
	string s;
	cin >> s;
	a.clear();
	pll pos = {0, 0};
	a[pos] = -1;
	ll mr = 0, mv = -1;
	for(ll i = 0;i<n;i++){
		if(s[i] == 'L') pos.x--;
		else if(s[i] == 'R') pos.x++;
		else if(s[i] == 'U') pos.y++;
		else pos.y--;
		if(a.count(pos)){
			if(i-a[pos] < mr || mv == -1){
				mr = i-a[pos];
				mv = i;
			}
		}
		a[pos] = i;
	}
	if(mv == -1){
		cout << -1;
	}else cout << mv+1-mr+1 << " " << mv+1;
	cout << '\n';
}

signed main(){
	FAST;
	ll q = 1;
	cin >> q;
	while(q--){
		solve();
	}
}