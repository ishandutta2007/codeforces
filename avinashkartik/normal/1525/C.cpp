#include<bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

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

const ll   N     =  5e5 + 2;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, m, a[N];
char b[N];
vector <ll> ans;

void calc(vector <ll> o) {
	for (int i = 0, j = o.size() - 1; i < j;) {
		if (b[o[i]] == b[o[i + 1]] && b[o[i]] == 'L') {
			ll d = (a[o[i]] + a[o[i + 1]]) / 2;
			ans[o[i]] = ans[o[i + 1]] = d;
			i += 2;
		} else if(b[o[j]] == b[o[j - 1]]){
			ll d = m - (a[o[j]] + a[o[j - 1]]) / 2;
			ans[o[j]] = ans[o[j - 1]] = d;
			j -= 2;
		} else {
			ll d = m - abs(a[o[j]] - a[o[j - 1]]) / 2;
			ans[o[j]] = ans[o[j - 1]] = d;
			j -= 2;
		}
	}
}

void solve() {
	cin >> n >> m;
	vector <ll> o, e, v(n);
	ans.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i], v[i] = i, ans[i] = -1;
	for (int i = 0; i < n; i++) cin >> b[i];
	sort(all(v), [&](int i, int j){
		return a[i] < a[j];
	});
	for (int i = 0; i < n; i++) {
		if (a[v[i]]&1) {
			if (o.size() == 0 || b[o.back()] == 'L' || b[v[i]] == 'R') 
				o.pb(v[i]);
			else {
				int d = (a[v[i]] - a[o.back()]) / 2;
				ans[v[i]] = d;
				ans[o.back()] = d;
				o.pop_back();
			}
		}
		else {
			if (e.size() == 0 || b[e.back()] == 'L' || b[v[i]] == 'R') 
				e.pb(v[i]);
			else {
				int d = (a[v[i]] - a[e.back()]) / 2;
				ans[v[i]] = d;
				ans[e.back()] = d;
				e.pop_back();
			}
		}
	}
	calc(o);
	calc(e);
	debv(ans)
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}