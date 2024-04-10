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
string s[55];
string t;
int n;
int calc(string x){
	int ans = 0;
	for(int i = 0; i < n; i++){
		string y = s[i];
		int mov = 0;
		while(mov < 100 && x != y) {
			char c = y[0];
			y.erase(y.begin());
			y += c;
			mov++;
		}
		if(mov == 100) return inf;
		ans += mov;
	}
	return ans;
}
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}
	t = s[0];
	int ans = inf;
	for(int j = 0; j < 2 * t.size(); j++){
		char c = t[0];
		t.erase(t.begin());
		t += c;
		ans = min(ans, calc(t));
	}
	if(ans == inf) ans = -1;
	cout << ans << endl;
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