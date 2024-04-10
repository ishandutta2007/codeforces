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
int n, p;
int a[100100];
int b[100100];

bool ok(double t){
	double sum = 0;
	for(int i = 0; i < n; i++){
		if(b[i] - a[i] * t >=0) continue;
		sum += (a[i] * t - b[i]);
	}

	if(sum <= t * p) return 1;
	return 0;

}

void solve(){
	scanf("%d%d", &n, &p);
	for(int i = 0; i < n; i++){
		scanf("%d%d", &a[i], &b[i]);
	}
	double l = 0, r = 1e11;
	int was = 0;
	for(int i = 0;  i<200; i++){
		double mid=(l + r)/2.0;
		if(ok(mid)){
			l = mid;
		}
		else {
			r = mid;
			was = 1;
		}
	}
	if(l > 1.5e10){
		printf("-1");
	}
	else printf("%.12lf\n", (l + r)/2.0);
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