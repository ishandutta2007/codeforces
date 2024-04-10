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

const int inf = (1ll << 25) - 1;
const int maxn = (int)1e6+20;
const int mod = (int) 1e9 + 7;
using namespace std;
ll w, m, k;
string s;
void solve(){
	cin >> w >> s >> k;
	int t=s.size();
	m = stoll(s);
	ll d = pow(10, t);
	ll ans = 0;
	while(w >= k*t) {
		ll z = min(w/t/k, (d - m));
		w -= z * k * t;
		t++;
		m = d;
		d *= 10;
		ans += z;
	}
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