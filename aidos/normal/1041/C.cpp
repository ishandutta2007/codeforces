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
pii a[200200];
int u[200200];
int m,d;
void solve(){
	cin >> n >> m >> d;
	set<pii> S;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i].f);
		a[i].s = i;
		S.insert(a[i]);
	}

	int g = 0;
	for(int i = 1; ; i++){
		if(S.size() == 0) break;
		g++;
		pii h = *S.begin();
		u[h.s] = g;
		S.erase(S.begin());
		while(true){
			set<pii> :: iterator it = S.lower_bound(mp(h.f+d + 1, -1));
			if(it == S.end()) break;
			h = *it;
			u[h.s] = g;
			S.erase(it);
		}
	}
	printf("%d\n", g);
	for(int i = 0; i < n; i++){
		printf("%d ", u[i]);
	}
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