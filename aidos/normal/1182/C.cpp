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
int n, m;
string s[100100];
vector<pii> g[1000100];
int ok(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'u' || c == 'o';
}
void solve(){
	cin >> n;
	int mx =  0;
	for(int i = 0; i < n; i++) {
		cin >> s[i];
		char c = '-';
		int cnt = 0;
		for(int j = 0; j < s[i].size(); j++){
			if(ok(s[i][j])) {
				c = s[i][j];
				cnt++;
			}
		}
		g[cnt].pb(mp(c, i));
		mx = max(mx, cnt);
	}
	vector<pii> ans1;
	vector<pii> ans2;
	for(int i=1;i <=mx; i++) {
		vector<pii> v;
		sort(all(g[i]));
		for(int j = 0; j < g[i].size(); j++) {
			if(v.size() && v.back().f == g[i][j].f) {
				ans2.pb(mp(v.back().s, g[i][j].s));
				v.pop_back();
			}
			else {
				v.pb(g[i][j]);
			}
		}
		for(int j = 1; j < v.size(); j+=2) {
			ans1.pb(mp(v[j].s, v[j-1].s));
		}
	}
	while(ans2.size() > ans1.size()) {
		ans1.pb(ans2.back());
		ans2.pop_back();
	}
	cout << ans2.size() << "\n";
	for(int i = 0; i < ans2.size(); i++) {
		cout << s[ans1[i].f] << " " << s[ans2[i].f] << "\n";
		cout << s[ans1[i].s] << " " << s[ans2[i].s] << "\n";
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