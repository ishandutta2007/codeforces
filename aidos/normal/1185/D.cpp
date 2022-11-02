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

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
int n;
vector<pll> a;
void check(ll x, ll d) {
	int cnt = 0;
	int ind = a[0].s;
	for(int i = 0; i < a.size(); i++) {
		if(cnt * 1ll * d + x == a[i].f) {
			cnt++;
		}else ind=a[i].s;
	}
	if(cnt >= n-1) {
		cout << ind + 1 << "\n";
		exit(0);
	}
}
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		a.pb(mp(x, i));
	}
	sort(all(a));
	check(a[0].f, a[1].f - a[0].f);
	check(a[0].f, a[2].f - a[0].f);
	check(a[1].f, a[2].f - a[1].f);
	cout << -1 << "\n";
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