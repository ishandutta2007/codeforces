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

const ll   N     =  3e5 + 2;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n;
string s;

void solve() {
	cin >> n >> s;
	int y = 0, z = 0;
 	for (int i = 0; i < (n + 1) / 2; i++) {
 		if (i == n - i - 1) {
 			if (s[i] == '0') y++;
 			continue;
 		}
 		if (s[i] == '1' && s[n - i - 1] == '0') y++, z++;
 		if (s[i] == '0' && s[n - i - 1] == '1') y++, z++;
 		if (s[i] == '0' && s[n - i - 1] == '0') y += 2;
 	}
 	if (z == 0) {
		if(y % 2 == 0) {
			if (y == 0) deb1("DRAW")
			else deb1("BOB")
		} else {
			if (y == 1) deb1("BOB")
			else deb1("ALICE")
		}
	} else {
		if (y == 2 && z == 1) deb1("DRAW")
		else deb1("ALICE")
	}
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}