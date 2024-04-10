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

int n, w, h;
vector< pii > x[400300], y[400300];
pii ans[200200];
deque<int> dq;
set<int> S;

void solve(){
	scanf("%d%d%d", &n, &w, &h);
	for(int i = 0, a, b, c; i < n; i++){
		scanf("%d%d%d", &a, &b, &c);
		int diff = b - c + 100000;
		S.insert(diff);
		if(a == 1){
			x[diff].pb(mp(b, i));
		}
		else y[diff].pb(mp(b, i));
	}
	forit(it, S){
		int v=*it;
		sort(all(x[v]));
		sort(all(y[v]));
		for(int i = 0; i < x[v].size(); i++){
			dq.pb(x[v][i].s);
		}
		for(int i = 0; i < y[v].size(); i++){
			dq.push_front(y[v][i].s);
		    int ind = dq.back();
		    dq.pop_back();
		    ans[ind] = mp(w, y[v][i].f);
		}
		for(int i = 0;i < x[v].size(); i++){
			int ind = dq.front();
			dq.pop_front();
			ans[ind] = mp(x[v][i].f, h);
		}
	}
	for(int i = 0; i < n; i++){
		printf("%d %d\n", ans[i].f, ans[i].s);
	}
}

int main () {
    //cout << "Hello world\n";
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}