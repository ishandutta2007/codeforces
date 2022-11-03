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
vector< pair<pii, int> > v;
int calc(int r1, int x2, int y2, int r2) {
	int a = -2*x2;
	int b = -2*y2;
	int c = x2*x2 + y2*y2 + r1*r1 - r2*r2;
	if (c*c > r1*r1*(a*a+b*b))
		return 0;
	else if (abs (c*c - r1*r1*(a*a+b*b)) == 0) {
		return 1;
	}
	else {
		return 2;	
	}
}
int inside(int r1, int x2, int y2, int r2) {
	if(r2 <= r1) return 0;
	return x2*x2 + y2 * y2 <= (r2-r1) * (r2-r1);
}

int outside(int r1, int x2, int y2, int r2) {
	if(r2 >= r1) return 0;
	return x2*x2 + y2 * y2 <= (r2-r1) * (r2-r1);
}
int ok(pair<pii, int> x) {
	for(int i = 0; i < v.size(); i++) {
		if(v[i].f == x.f) continue;
		if(calc(x.s, v[i].f.f-x.f.f, v[i].f.s - x.f.s, v[i].s) == 2) return 0;
	}
	
	int I = 0, O = 0;
	for(int i = 0; i < v.size(); i++) {
		if(v[i].f == x.f) continue;
		if(inside(x.s, v[i].f.f-x.f.f, v[i].f.s - x.f.s, v[i].s)) {
			if(i % 2 == 0) return 1;
			return 0;
		}
	}
	//cout << I << " "<<O << "\n";
	return 1;
}
void solve(){
	for(int i = 0; i < 2; i++) {
		int x, y, r, R;
		cin >> x >> y >> r >> R;
		v.pb(mp(mp(x, y), r));
		v.pb(mp(mp(x, y), R));
	}
	int ans = 0;
	for(int i = 0; i < v.size(); i++) ans += ok(v[i]);
	cout << ans << "\n";
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