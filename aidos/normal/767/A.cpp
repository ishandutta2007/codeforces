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
int used[100100];
int u[100100];
vector<int> v;
void solve(){
	scanf("%d", &n);
	u[n+1] = 1;

	for(int i = 0, x; i < n; i++){
		scanf("%d", &x);
		used[x] = 1;
		v.clear();
		if(u[x+1] == 1){
			while(!u[x] && used[x]){
				u[x] = 1;
				v.pb(x);
				x--;
			}
		}
		for(int j = 0; j < v.size(); j++){
			if(j) printf(" ");
			printf("%d", v[j]);
		}
		printf("\n");
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