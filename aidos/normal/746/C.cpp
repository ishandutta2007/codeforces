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
int s, x1, x2, t1, t2, p, d;
void solve(){
	cin >> s >> x1 >> x2 >> t1 >> t2 >> p >> d;
	if(t1 >= t2){
		printf("%d\n",abs(x2-x1) * t2);
		return;
	}
	int ans = abs(x2-x1) * t2;
	int cur = 0;
	while(true){
		if(p == x1){
			break;
		}
		if(p == 0 || s == p) d *= -1;
		p += d;
		cur += t1;
	}
	while(true){
		if(p == x2) break;
		if(p == 0 || s == p) d *= -1;
		p += d;
		cur += t1;
	}
	printf("%d\n", min(ans, cur));
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