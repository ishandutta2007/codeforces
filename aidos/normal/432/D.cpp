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
#include <unordered_map>

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

const int inf = 100100;
const int maxn = (int) 1e5 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
int n;
int z[100100];
int c[100100];
string s;
vector<pii> ans;
void solve(){
	cin >> s;
	n = s.size();
	for(int i = 1, l = 0, r = 0; i < n; i++) {
		if(r > i) z[i] = min(z[i-l], r-i);
		while(z[i] + i < n && s[i + z[i]] == s[z[i]]) ++z[i];
		if(i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
	}
	for(int i = 1; i < n; i++) c[z[i]]++;
	for(int i = n; i>=1; i--) c[i] += c[i+1];
	for(int i = n-1; i >= 1; i--) {
		if(z[i] + i == n) {
			ans.pb(mp(z[i], c[z[i]] + 1));
		}
	}
	ans.pb(mp(n, 1));
	//reverse(all(ans));
	cout << ans.size() << "\n";
	for(int i = 0; i < ans.size(); i++) cout << ans[i].f << " " << ans[i].s << "\n";
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