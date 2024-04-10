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
const int maxn = (int) 2e5 + 10;
using namespace std;
int n, k;
int dp[222][222][444];
string s, t;
int get(int i, int j, int k) {
	if(k > 404) return inf;
	if(k < 0) return inf;
	if(i == s.size() && j == t.size() && k == 0) return 0;
	int &res = dp[i][j][k];
	if(res != -1) return res;
	res = inf;
	int ti = i;
	int tj = j;
	if(ti < s.size() && s[ti] == '(') ti++;
	if(tj < t.size() && t[tj] == '(') tj++;
	res = min(res, get(ti, tj, k+1) + 1);
	ti = i;
	tj = j;
	if(ti < s.size() && s[ti] == ')') ti++;
	if(tj < t.size() && t[tj] == ')') tj++;
	res = min(res, get(ti, tj, k-1) + 1);
	return res;
}
void rec(int i, int j, int k) {
	if(i == s.size() && j == t.size() && k == 0) return;
	
	int res = get(i, j, k);
	int ti = i;
	int tj = j;
	if(ti < s.size() && s[ti] == '(') ti++;
	if(tj < t.size() && t[tj] == '(') tj++;
	if(res == get(ti, tj, k+1) + 1) {
		cout << '(';
		rec(ti, tj, k+1);
		return;
	}
	ti = i;
	tj = j;
	if(ti < s.size() && s[ti] == ')') ti++;
	if(tj < t.size() && t[tj] == ')') tj++;
	cout << ')';
	rec(ti, tj, k-1);
}
void solve(){    
	cin >> s >> t;
	memset(dp, -1, sizeof dp);
	rec(0, 0, 0);
}
int main () {
	int t=1;
	//cin >> t;
	for(int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}