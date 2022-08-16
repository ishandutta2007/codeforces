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

ll n;
string s;

bool ch(string s) {
	int f = 0;
	for(auto it : s) {
		if(it == '(') f++;
		else f--;
		if(f < 0) return 0;
	}
	return f == 0;
}

void solve() {
	cin >> n >> s;
	string a(n, '0'), b(n, '0');
	int cta = 0, ctb = 0;
	deque <int> l;
	for(int i = 0; i < n; i++) {
		if(s[i] == '0') {
			if(cta == 0 && ctb == 0) {
				if(l.size() == 0){
					deb1("NO")
					return;
				} else {
					a[l.front()] = '(';
					b[l.front()] = '(';
					l.pop_front();
					cta++;
					ctb++;
				}
			}
			if(cta > ctb) {
				cta -= 1;
				a[i] = ')';
				ctb += 1;
				b[i] = '(';
			} else {
				cta += 1;
				a[i] = '(';
				ctb -= 1;
				b[i] = ')';
			}
		} else {
			l.pb(i);
		}
	}
	if(cta != ctb) {
		deb1("NO")
		return;
	}
	int k = (l.size() - cta) / 2;
	for(int i = 0; i < l.size(); i++) {
		if(i < k) {
			a[l[i]] = b[l[i]] = '(';
		} else {
			a[l[i]] = b[l[i]] = ')';
		}
	}
	if(ch(a) && ch(b)){
		deb1("YES")
		deb1(a)
		deb1(b)
	} else deb1("NO")
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}