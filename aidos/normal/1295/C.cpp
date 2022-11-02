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
const int maxn = (int) 3e5 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
string s;
string t;
int nxt[100100][26];
void solve(){
	cin >>s >> t;
	int n = s.size();
	for(int i = 0; i < 26; i++) nxt[n][i] = -1;
	for(int i = n-1; i >= 0; i--) {
		for(int j = 0; j < 26; j++) nxt[i][j] = nxt[i+1][j];
		nxt[i][s[i] - 'a'] = i;
	}
	int p = n, ans = 0;
	for(int i = 0;i < t.size(); i++) {
		int c = t[i] - 'a';
		if(nxt[p][c] == -1) {
			if(nxt[0][c] == -1) {
				cout << -1 << "\n";
				return;
			}
			p = nxt[0][c] + 1;
			ans++;
		}else {
			p = nxt[p][c] + 1;
		}
	}
	cout << ans << "\n";
}

int main () {
    int t=1;
    scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }
    
    return 0;
}