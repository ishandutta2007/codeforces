#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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
using namespace __gnu_pbds;


typedef tree<
	ll,
	null_type,
	less<int>,
	rb_tree_tag,
	tree_order_statistics_node_update
> ordered_set;

vector<ll> a[N];
ll mina[N], maxa[N], maxp[N*10], maxpf[N*10];
bool have[N];
signed main(){
	FAST;
	ll n;
	cin >> n;
	ll res = 0;
	ll mall = 0;
	ll hall = 0;
	for(ll i = 0;i<n;i++){
		ll sz;
		cin >> sz;
		a[i].reserve(sz);
		ll mbf = INF;
		bool flag = 0;
		for(ll k, j = 0;j<sz;j++){
			cin >> k;
			a[i].pb(k);
			mina[i] = (j == 0 ? k : min(mina[i], k));
			maxa[i] = (j == 0 ? k : max(maxa[i], k));
			mall = max(mall, k);
			if(!flag){
				if(mina[i] < k) flag = 1;
			}
		}
		have[i] = flag;
		if(have[i]) hall++;
		else maxp[maxa[i]]++;
	}
	maxpf[0] = maxp[0];
	for(ll i = 1;i<=mall;i++) maxpf[i] = maxpf[i-1]+maxp[i];
	for(ll i = 0;i<n;i++){
		if(have[i]) res += n;
		else{
			res += n-maxpf[mina[i]];
		}
	}
	cout << res << endl;
}