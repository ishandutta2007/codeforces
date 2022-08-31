#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()
#define  ordered_set 	tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>


typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll, ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  2e5 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, k, a[N], b[N];

int ch(int x){
	for(int i = 1; i <= n; i++) b[i] = (a[i] < x)? -1 : 1;
	int s = 0, p = 0, mn = 0;
	for(int i = 1; i <= k; i++) s += b[i];
	int f = (s >= 1);
	for(int i = k + 1; i <= n; i++){
		s += b[i];
		p += b[i - k];
		mn = min(mn, p);
		f |= (s - mn >= 1);
	}
	return f;
}

void solve() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	int l = 1, r = n;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(ch(mid)) l = mid + 1;
		else r = mid - 1;
	}
	deb1(l - 1)
}

int main() {
	GODSPEED;
	int test = 1;
	//cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}