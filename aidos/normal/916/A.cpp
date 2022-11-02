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
int x;
int h, m;
int ok(int a){
	if(a % 10 == 7) return 1;
	if(a/10 == 7) return 1;
	return 0;
}
int good(int x){
	int a = x % 60;
	int b = x/60;
	return ok(a) || ok(b);
}
void solve(){
	cin >> x >> h >> m;
	int d = 24 * 60;
	for(int i = 0; ; i++){
		int mi = h * 60 + m;
		mi -= x * i;
		mi %= d;
		if(mi<0) mi += d;
		if(good(mi)){
			cout << i << endl;
			return;
		}
	}
}

int main () {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}