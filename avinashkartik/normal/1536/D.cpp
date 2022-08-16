#include<bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

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

typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll, ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  3e5 + 5;
const ll   mod   = 	998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, a[N];
string s;

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	ordered_set s;
	map <ll, int> m;
	for (int i = 1; i <= n; i++) {
		if (m.find(a[i]) == m.end()) s.insert(a[i]);
		int ind = s.order_of_key(a[i]) + 1;
		int left = 2 * i - 1 - s.size();
		if (ind < i) {
			while (ind < i) {
				if (left == 0) break;
				s.insert(-INFi);
				left--;
				ind++;
			}
		}
		if (ind == i) {
			while (left) {
				s.insert(INFi);
				left--;
			}
		}
		if (ind != i) {
			deb1("NO")
			return;
		}
		m[a[i]]++;
	}
	deb1("YES")
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}