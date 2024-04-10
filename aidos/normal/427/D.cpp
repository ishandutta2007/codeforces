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
string s1, s2, s;
int col[100100];
pii d[100100];
int suff[100100];
int lcp[100100];
bool cmp(int i, int j) {
	return d[i] < d[j];
}
void solve(){
	cin >> s1 >> s2;
	s = s1;
	s += 'a'-1;
	s += s2;
	s += 'a'-2;
	for(int i = 0; i < s.size(); i++) {
		col[i] = s[i] - 'a' + 2;
		d[i] = mp(col[i], col[i]);
		suff[i] = i;
	}
	sort(suff, suff + s.size(), cmp);
	for(int l = 0; (1<<l) <= s.size(); l++){
		for(int i  = 0; i < s.size(); i++) {
			d[i] = mp(col[i], col[(i+(1<<l)) % s.size()]);
		}
		sort(suff, suff + s.size(), cmp);
		int cn = 0;
		for(int i = 0;i < s.size(); i++) {
			if(i == 0 || d[suff[i]] != d[suff[i-1]]) {
				col[suff[i]] = cn;
				cn++;
			}else {
				col[suff[i]] = cn-1;
			}
		}
	}
	for(int i = 0; i + 1< s.size(); i++) {
		while(suff[i] + lcp[i] < s.size() && s[suff[i] + lcp[i]] == s[suff[i+1] + lcp[i]]) lcp[i]++;
	}
	int ans = inf;
	for(int i = 0; i < s.size(); i++) {
		if(lcp[i] == 0) continue;
		int x = suff[i] < s1.size();
		int y = suff[i+1] < s1.size();
		if(x == y) continue;
		if(lcp[i-1] >= lcp[i]) continue;
		if(lcp[i+1] >= lcp[i]) continue;
		ans = min(ans, max(lcp[i-1], lcp[i+1]) + 1);
	}
	if(ans == inf) ans = -1;
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