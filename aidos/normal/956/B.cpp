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
int n, U;
int a[100100];
void solve(){
	scanf("%d%d", &n, &U);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	double ans = -inf;
	int was = 0;
	for(int i = 0; i < n; i++){
		int k = upper_bound(a, a + n, a[i] + U) - a - 1;
		if(k < i + 2) continue;
		int j = i + 1;
		was = 1;
		ans = max(ans, (a[k] - a[j]+0.0)/(a[k] - a[i]));
		
	}
	if(was) printf("%.12lf\n", ans);
	else printf("-1\n");	
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