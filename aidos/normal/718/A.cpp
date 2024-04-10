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
char c[200200];
int n, t;
void solve(){
	scanf("%d%d", &n, &t);
	scanf("%s", c);
	int pos = 0;
	for(int i = 0; i < n; i++)
		if(c[i] == '.') pos = i;
	int x = pos + 1;
	while( x < n && c[x] < '5') {
		x++;
	}
	if(x == n) {
		printf("%s\n", c);
		return;
	}
	int add = 0;
	while(t > 0 && c[x] >= '5'){
		x--;
		t--;
		if(x == pos) {
			add = 1;
			break;
		}
		c[x]++;
	}
	if(add){
		vector<int> cc;
		int car = 1;
		for(int i = pos-1; i >= 0; i--){
			int xx = c[i] - '0' + car;
			cc.pb(xx % 10);
			car = xx/10;
		}
		if(car > 0) {
			cc.pb(car);
		}
		reverse(all(cc));
		for(int i = 0; i < cc.size(); i++)
			printf("%d", cc[i]);
		return;
	}
	c[x+1] = 0;
	printf("%s\n", c);
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