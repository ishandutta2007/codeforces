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
int a[5050];
pair< pii, int > d[2020];
int ans[2020];
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> d[i].f.f >> d[i].s;
		d[i].f.s = i;
		ans[i] = 0;
	}
	int c = 0;
	sort(d, d + n);
	set< pair<pii, int> > S;
	for(int i = 0; i < n; i++){
		S.insert(d[i]);
	}
	while(S.size() > 0){
		if(S.begin()->f.f > c) c = S.begin()->f.f;
		if(S.begin()->s < c){
			S.erase(S.begin());
		}
		else {
			ans[S.begin()->f.s] = c;
			S.erase(S.begin());
			c++;
		}
	}
	for(int i = 0; i < n; i++){
		cout << ans[i];
		if(i + 1< n) cout << " ";
		else cout << "\n";
	}
}

int main () {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
    int t=1;
    scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}