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
char c[555][555];
int n, m, k;
vector<pair<int, pii>>a;
void solve(){
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++) cin >> c[i];
	for(int i = 0; i < n; i++) {
	    for(int j = 0; j < m; j++) {
	        if(c[i][j] == '*') {
	            int lim = min(min(m-j-1, j), min(i, n-i-1));
	            for(int t = 1; t <= lim; t++) {
	                if(c[i][j-t] == '*' &&c[i][j+t] == '*' && c[i-t][j] == '*' && c[i+t][j] == '*') {
	                    a.pb(mp(t, mp(i, j)));
	                }
	            }
	        }
	    }
	}
	if(a.size() >= k) {
	    std::nth_element(a.begin(), a.begin() + k-1, a.end());
	    int x = a[k-1].s.f+1;
	    int y = a[k-1].s.s+1;
	    int t=a[k-1].f;
	    cout << x << " "<< y << "\n";
	    cout << x-t << " "<< y << "\n";
	    cout << x+t << " "<< y << "\n";
	    cout << x << " "<< y-t << "\n";
	    cout << x << " "<< y+t << "\n";
	}
	else cout << -1 <<"\n";
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