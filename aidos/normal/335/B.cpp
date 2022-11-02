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
const int maxn = (int)1e5 + 10; //maximum + 10
const int mod = (int) 1e9 + 7;
using namespace std;

int n, k;
string s;
int cnt[29];
int dp[2610][2610];
int get(int l, int r) {
	if(l > r) return 0;
	if(l == r) return 1;
	int &res = dp[l][r];
	if(res != -1) return res;
	res = max(get(l, r-1), get(l+1, r));
	if(s[l] == s[r]) res = max(get(l+1, r-1)+2, res);
	return res;
}
void rec(int l, int r, int len) {
	if(l > r) return;
	if(len == 0) return;
	if(l == r) {
		cout << s[l];
		return;
	}
	if(get(l, r-1) == get(l, r)) {
		rec(l,r-1, len);
		return;
	}

	if(get(l+1, r) == get(l, r)) {
		rec(l+1,r, len);
		return;
	}
	cout << s[l];
	rec(l+1, r-1, len-2);
	cout << s[r];
}
void solve(){
	cin >> s;
	for(int i = 0; i < 26; i++) {
		cnt[i] = 0;
		for(int j = 0; j < s.size(); j++)
			if(s[j] == i + 'a') cnt[i]++;
		if(cnt[i] >= 100) {
			for(int j = 0; j < 100; j++)
				cout << char(i + 'a');
			cout << "\n";
			return;
		}
	}
	memset(dp, -1, sizeof dp);
	int x = get(0, s.size()-1);
	rec(0, s.size()-1, min(x, 100));
}
int main () {

	int t = 1;
	//scanf("%d", &t);
	for(int i=1; i<=t; i++){
		//printf("Case #%d: ", i);
		solve();
	}
    return 0;
}