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
int n;
void solve(){
	cin >> n;
	vector<pii> v;
	for(int i = 1; i <= n; i++) {	
		int l, r;
		cin >> l >> r;
		v.pb(mp(l, 1));
		v.pb(mp(r+1, -1));
	}
	sort(all(v));
	int ans = 0;
	int cur = 0;
	for(int i = 0; i < v.size(); ) {
		int j = i;
		while(i < v.size() && v[i].f == v[j].f) {
			cur += v[i].s;
			i++;
		}
		ans=max(ans, cur);
		
	}
	if(ans > 2) cout << "NO\n";
	else cout << "YES\n";
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