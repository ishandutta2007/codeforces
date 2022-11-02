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

const int inf = (1 << 29) - 1;
const int maxn = (int)1e6 + 10; //maximum + 10
const int mod = (int) 1e9 + 7;
using namespace std;
int n;
vector<int> g[2];
int a[100][100];
void solve(){
	cin >> n;
	for(int i = 1; i <= n * n; i++) {
		g[i % 2].pb(i);
	}
	int cnt = g[1].size();
	vector< pii > c;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i == n/2 || j == n/2) {
				a[i][j] = 1;
				cnt--;
			} else if(max(i,j) < n/2) {
				c.pb(mp(i, j));
			}
		}
	}

	for(int i = 0; i < cnt/4; i++) {
		int x = c[i].f;
		int y = c[i].s;
		a[x][y] = 1;
		a[x][n-y-1] = 1;
		a[n-x-1][y] = 1;
		a[n-x-1][n-y-1] = 1;
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			int x = a[i][j];
			cout << g[x].back() << " ";
			g[x].pop_back();
		}
		cout << "\n";
	}
}
int main () {

    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d: ", i);
      solve();
    }
    
    return 0;
}