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
#include <bits/stdc++.h>

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

using namespace std;
int n, m;
vector< int > g[5050];

char  op[5050];
int dp[5050];
string val[5050];
map<string, int> M;

int get(int pos, int d){
	dp[0] = d;
	int sum = 0;
	for(int i = 1; i <= n; i++){
		if(val[i].size()){
			dp[i] = val[i][pos] - '0';
		}
		else {
			int j = g[i][0];
			int k = g[i][1];
			if(op[i] == 'A'){
				dp[i] = dp[j] & dp[k];
			}else if( op[i] == 'X'){
				dp[i] = dp[j] ^ dp[k];
			}else {				
				dp[i] = dp[j] | dp[k];
			}
		}
		sum += dp[i];
	}
	return sum;
}
void solve(){
	string s;
	getline(cin, s);
	std::stringstream ss(s);
	ss >> n >> m;
	M["?"] = 0;
	for(int i = 1; i <= n; i++){	
		getline(cin, s);
		std::stringstream ss(s);
		vector<string> cur;
		while(ss >> s){
			cur.pb(s);
		}
		M[cur[0]] = i;
		if(cur.size() == 3){
			val[i] = cur[2];
		}
		else {
			g[i].pb(M[cur[2]]);
			op[i] = cur[3][0];
			g[i].pb(M[cur[4]]);
		}
	}
	string mi, mx;
	for(int i = 0; i < m; i++){
		int c1 = get(i, 0);
		int c2 = get(i, 1);
		mi += (c1 <= c2) ? "0" : "1";
		mx += (c1 >= c2)? "0" : "1";
	}
	cout << mi << endl<< mx << endl;
}

int main () {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}