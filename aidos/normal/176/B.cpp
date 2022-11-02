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
string s;
string x;
ll dp[200200], d[200200];
int k;
int z[100100];
void solve(){
	cin >> s>>x >> k;
	string t = x + '#' + s + s;
	int n = t.size();
	for(int i = 1, l = 0, r = 0; i < n; i++){
		if(i <= r) z[i] = min(r-i, z[i-l]);
		while(i + z[i] < n && t[z[i]] == t[i+z[i]]) ++z[i];
		if(i + z[i] - 1 >= r){
			r = i + z[i] - 1;
			l = i;
		}
	}
	int A = 0, B = 0;
	for(int i = 0; i < s.size(); i++) {
		A += z[x.size()+1+i] == x.size();
		B += z[x.size()+1+i] != x.size();
	}
	if(s == x) dp[0] = 1;
	else d[0] = 1;
	for(int i = 1; i <= k; i++){
		dp[i] = (dp[i-1] * (A-1) + d[i-1] * A) % mod;
		d[i] = (d[i-1] * (B-1) + dp[i-1] * B) % mod;
	}
	cout << dp[k] << "\n";
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