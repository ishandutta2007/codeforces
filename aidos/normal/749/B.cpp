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

int x[333], y[333];
void solve(){
	set<pii> S;
	for(int i = 0; i < 3; i++){
		scanf("%d%d", &x[i], &y[i]);
	}
	for(int i = 0; i < 3; i++){
		for(int j = i + 1; j < 3; j++){
			int k = 3 - i - j;
			S.insert(mp(x[i] + x[j] - x[k], y[i] + y[j] - y[k]));
		}
	}
	cout << S.size() << endl;
	forit(it, S){
		printf("%d %d\n", it->f, it->s);
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