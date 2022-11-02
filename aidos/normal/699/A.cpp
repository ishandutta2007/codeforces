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
int n;
vector<pii> v;
char c[200200];
void solve(){
	scanf("%d", &n);
	scanf("%s", c);
	for(int i = 0, x; i < n; i++){
		scanf("%d", &x);
		if(c[i] == 'L')
			v.pb(mp(x, 0));
		else v.pb(mp(x, 1));
	}
	sort(all(v));
	int ind = -1, j = 0, ans = 2e9;
	
	while(j < n){
		while(j < n && v[j].s) {
			ind = j;
			j++;
		}
		while(j <n && v[j].s == 0){
			if(ind != -1){
				ans = min(ans, (v[j].f - v[ind].f)/2);
			}
			j++;
		}
	}
	if(ans > 1e9) ans = -1;
	printf("%d\n", ans);
}

int main () {

    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Test case #%d\n", i);
      solve();
    }

    return 0;
}