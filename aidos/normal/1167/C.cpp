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
int n, q;
int p[500500];
int sz[500500];
int get(int v){
    if(p[v] == v) return v;
    return p[v] = get(p[v]);
}
void solve(){
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++) {
	    p[i] = i;
	    sz[i] = 1;
	}
	for(int i = 0; i < q; i++){
	   int k;
	   scanf("%d", &k);
	   int y = -1;
	   for(int j = 0; j < k; j++){
	       int x;
	       scanf("%d", &x);
	       if(y == -1) y = x;
	       else {
	           y = get(y);
	           x = get(x);
	           if(x!=y) {
	               p[x] = y;
	               sz[y] += sz[x];
	           }
	       }
	   }
	}
	for(int i = 1; i <= n; i++) printf("%d\n", sz[get(i)]);
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