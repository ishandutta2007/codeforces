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

using namespace std;

ll calc(ll n, ll m){
	ll d = n/m;
	return n * n - d * d;
}

void solve(){
	int x;
	cin >> x;

	for(ll i = 1; i <= 100100; i++){
		if(i * i <= x) continue;
		ll d = sqrt(i * i - x);
		if(d * d + x == i * i){
			ll y = i/d;
			for(int t = -5; t <= 5; t++){
				if(y + t > 0 && y + t <= i && calc(i, y + t)==x){
					cout << i << " "<< y + t << endl;
					return;
				}
			}
		}
	}
	cout << -1 << endl;
	return;
}

int main () {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
    int t=1;
    scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}