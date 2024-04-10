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
const ll N = 5228;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;
ll a[N];
ll cnt[N];
python solve(){
	FAST;
	memset(cnt, 0, sizeof(cnt));
	ll n;
	cin >> n;
	bool ok = 0;
	for(ll i = 1;i<=n;i++){
		cin >> a[i];
		cnt[a[i]]++;
		if(cnt[a[i]] > 2 || (cnt[a[i]] == 2 && a[i-1] != a[i])) ok = 1;
	}
	if(ok)cout << "YES\n";
	else cout << "NO\n";
}

signed main(){
	FAST;
	ll q = 1;
	cin >> q;
	while(q--){
		solve();
	}
}