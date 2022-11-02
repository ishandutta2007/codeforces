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
#include <bitset>

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
int n, m;
string s[300];
void solve(){
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> s[i];
	s[0][0] = 'W';
	vector<pii> a;
	for(int i = 0; i < n; i++) {
		if(i % 2 == 0){
			for(int j = 0; j < m; j++) if(s[i][j] == 'W') a.pb(mp(i, j));
		}
		else{
			for(int j = m-1; j>=0; j--) if(s[i][j] == 'W') a.pb(mp(i, j));
		}
	}
	int ans = 0;
	for(int i = 1; i < a.size(); i++) {
		ans += abs(a[i-1].s - a[i].s) + a[i].f - a[i-1].f;
	}
	cout << ans << "\n";
	
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