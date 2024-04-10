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

vector<pii> ans, a;
int n;
char c[100];
void solve(){
	scanf("%d", &n);
	for(int i = 0, type, x; i < n; i++){
		scanf("%s", c);
		if(c[0] == 'i') {
			type = 0;
			scanf("%d", &x);
		}else if(c[0] == 'g') {
			type = 1;
			scanf("%d", &x);
		}else{
			type = 2;
		}
		a.pb(mp(type, x));
	}
	set<pii> S;
	int id = 0;
	for(int i = 0; i < a.size(); i++){
		if(a[i].f == 2){
			if(S.size()){
				S.erase(S.begin());
			}else{
				ans.pb(mp(0, 1));
			}
			ans.pb(a[i]);
		}
		else if(a[i].f == 0){
			ans.pb(a[i]);
			S.insert(mp(a[i].s, id));
			id++;
		}else {
			while(S.size() && S.begin()->f < a[i].s){
				ans.pb(mp(2, 1));
				S.erase(S.begin());
			}
			if(S.size() && S.begin()->f == a[i].s) {
				
				ans.pb(a[i]);
				continue;
			}
			ans.pb(mp(0, a[i].s));
			S.insert(mp(a[i].s, id));
			id++;
			ans.pb(a[i]);
		}
	}
	printf("%d\n", ans.size());
	for(int i = 0; i < ans.size();i++){
		if(ans[i].f == 0) printf("insert %d\n", ans[i].s);
		else if(ans[i].f == 1) printf("getMin %d\n", ans[i].s);
		else printf("removeMin\n");
	}
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Test case #%d\n", i);
      solve();
    }


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}