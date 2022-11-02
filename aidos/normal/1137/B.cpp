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
char s[500500];
char t[500500];
int dp[500500][2];
vector<int> prefix_function (string s) {
	int n = (int) s.length();
	vector<int> pi (n);
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi;
}
int cnt[11];
string calc(string s, string t){
	vector<int> p = prefix_function(s);
	dp[0][s[0]-'0'] = 1;
	for(int i = 1; i < p.size(); i++){
		dp[i][s[i]-'0'] = i + 1;
		int g = s[i] - '0';
		g ^= 1;
		dp[i][g] = dp[p[i]][g];
	}
	for(int i = 0; i < t.size(); i++) cnt[t[i]-'0']++;
	string ans = "";
	int cur = 0;
	for(int i = 0; i < t.size(); i++) {
		if(cnt[0] == 0) {
			ans += '1';
		}else if(cnt[1] == 0) {
			ans += '0';
		}else{
			int g1 = dp[cur][0];
			int g2 = dp[cur][1];
			if(g1 > g2) {
				ans += '0';
				cur = g1;
				cnt[0]--;
			}else {
				ans += '1';
				cur = g2;
				cnt[1]--;
			}
			if(cur == s.size()){
				cur = p[cur-1];
			}
		}
	}
	return ans;
}
void solve(){
	scanf("%s%s", t, s);
	cout << calc(s, t) << "\n";
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