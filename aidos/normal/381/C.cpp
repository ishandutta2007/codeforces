#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <bitset>
#include <unordered_map>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int inf = 100100;
const int maxn = (int) 1e5 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
int a[3*maxn];
ll n = 0;
ll cur = 0;
int m, q;
vector< pll > v;
pair<int, pii>Q[100100];
void solve(){
	cin >> m;
	for(int i = 0; i < m; i++) {
		int ty;
		cin >> ty;
		if(cur < maxn) {
			if(ty == 1) {
				cin >> a[cur];
				cur++;
				n++;
			}
			else {
				ll l, r;
				cin >> l >> r;
				while(cur < maxn && r > 0) {
					for(int j = 0; j < l; j++) {
						a[cur] = a[j];
						cur++;
						n++;
					}
					r--;
				}
				if(r>0) {
					Q[i] = mp(2, mp(l, r));
					v.pb(mp(cur, i));
					cur += l * r;
				}
			}
		}else {
			if(ty == 1) {
				int x;
				cin >> x;
				v.pb(mp(cur, i));
				Q[i] = mp(1, mp(x, -1));
				cur++;
			}
			else {
				ll l, r;
				cin >> l >> r;
				if(r>0) {
					Q[i] = mp(2, mp(l, r));
					v.pb(mp(cur, i));
					cur += l * r;
				}
			}
		}
	}
	cin >> q;
	for(int i = 0; i < q; i++) {
		ll d;
		cin >> d;
		d--;
		if(d < n) cout << a[d] << "\n";
		else {
			int pos = upper_bound(all(v), mp(d, inf*1ll)) - v.begin()-1;
			int ind = v[pos].s;
			ll val = d-v[pos].f;
			if(Q[ind].f == 1) cout << Q[ind].s.f << "\n";
			else {
				val %= Q[ind].s.f;
				cout << a[val] << "\n";
			}
		}
	}
}	

int main () {
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}