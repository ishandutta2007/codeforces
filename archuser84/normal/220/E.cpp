///
///    Hashire sori yo 
///    Kaze no you ni  
///    Tsukimihara wo  
///    PADORU PADORU   
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

const int N = 100'010;
ll n, k;
int a[N];

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> k; Loop(i,0,n) cin >> a[i], a[i] = -a[i];
	ll cnt = 0;
	oset L, R;
	int l = n-1, r = n-1;
	Loop(i,0,n-1){
		cnt += L.order_of_key(a[i]);
		L.insert(a[i]);
	}
	cnt += L.order_of_key(a[r]);
	R.insert(a[r]);
	if(cnt <= k) Kill(n*(n-1)/2);
	ll ans = 0;
	while(r){
		while(l && cnt > k){
			--l;
			cnt -= L.order_of_key(a[l]);
			cnt -= R.size() - R.order_of_key(a[l]+1);
			L.erase(L.upper_bound(a[l]));
		}
		ans += l;
		--r;
		cnt += L.order_of_key(a[r]);
		cnt += R.size() - R.order_of_key(a[r]+1);
		R.insert(a[r]);
	}
	cout << ans << '\n';
}