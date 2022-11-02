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
long long a,b;
ll ans = 0;
ll K = 0;
void calc(ll x){
	ll k = (x - a%x) % x;
	if(ans > (a+k) * 1ll * (b+k)/x){
		ans = min(ans, (a+k) * 1ll * (b+k)/x);
		K = k;
	}else if(ans == (a+k) * 1ll * (b+k)/x){
		K = min(k, K);
	}
}
void solve(){
	cin >> a >> b;
	if(a == b) {
		cout << 0;
		return;
	}
	ll d = abs(a-b);
	ans = a*1ll*b;
	K = 0;
	for(int i = 1; i*i <= d; i++){
		if(d % i == 0) {
			calc(i);
			calc(d/i);
		}
	}
	cout << K;
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