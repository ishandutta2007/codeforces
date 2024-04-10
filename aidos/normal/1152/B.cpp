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
long long x;
int ok(ll y) {
	while(y > 0) {
		if(y % 2 == 0) return 0;
		y/=2;
	}
	return 1;
}
void solve(){
	cin >> x;
	vector<ll> res;
	for(int i = 0; !ok(x); i++){
		if(i%2==0) {
			long long d = 0;
			int cnt = 0;
			while(d < x) {
				d = d * 2 + 1;
				cnt++;
			}
			x ^= d;
			res.pb(cnt);
		}
		else {
			x = x + 1;
			res.pb(-1);
		}
	}
	cout << res.size() << "\n";
	for(int i = 0; i < res.size(); i+= 2) cout << res[i] << " ";
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