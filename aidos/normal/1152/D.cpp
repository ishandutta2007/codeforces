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

pair<pii,int> dp[2010][2010];
int was[2010][2010];

int n;
pair<pii, int> rec(int p, int bal) {
	if(bal < 0) return mp(mp(1, 0), 0);
	if(p == n) {
		if(bal == 0) {
			return mp(mp(0, 0), 1);
		}
		return mp(mp(1, 0), 0);
	}
	if(was[p][bal]) return dp[p][bal];
	was[p][bal] = 1;
	pair<pii, int> a = rec(p+1, bal+1);
	pair<pii, int> b = rec(p + 1, bal - 1);
	if(!a.f.f && a.s) {
		dp[p][bal] = mp(mp(1, (a.f.s + b.f.s + 1) % mod), 1);
	}else if(!b.f.f && b.s){
		dp[p][bal] = mp(mp(1, (a.f.s + b.f.s + 1) % mod), 1);
	} else {
		dp[p][bal] = mp(mp(0, (a.f.s + b.f.s) % mod), a.s|b.s);
	}
	return dp[p][bal];
}
void solve(){
	cin >> n;
	n*=2;
	pair<pii, int> a = rec(0, 0);
	cout << a.f.s << "\n";
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