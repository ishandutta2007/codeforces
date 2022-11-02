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

using namespace std;
ll x[111][111][111];

ll y[111][111][111];
int n, m;
int mod = 1000*1000*1000+7;
string s;
int p[111];
void solve(){
	cin >> n >> m;
	cin >> s;
	s += '#';
	for(int i = 1; i <= n; i++){
		int j = p[i-1];
		while(j > 0 && s[i] != s[j]){
			j = p[j-1];
		}
		if(s[i] == s[j]) j++;
		p[i]=j;
	}
	for(int i = 0; i <= n; i++){
		x[0][i][i]++;
		int j = i;
		while(j>0 && s[j] != '0') j = p[j-1];
		if(s[j] == '0') {
			j++;
			x[0][i][j]++;
			if(j == n) y[0][i][j]++;
		}
		else x[0][i][j]++;
	}
	for(int i = 0; i <= n; i++){
		
		x[1][i][i]++;
		int j = i;
		while(j>0 && s[j] != '1') j = p[j-1];
		if(s[j] == '1') {
			j++;
			x[1][i][j]++;
			if(j == n) y[1][i][j]++;
		}
		else x[1][i][j]++;
	}
	for(int it = 2; it <= m; it++){
		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= n; j++){
				ll res1 = 0, res2 = 0;
				for(int k = 0; k<=n; k++){
					res1 += x[it-1][i][k] * x[it-2][k][j];
					if(res1>1e15) res1 %= mod;
					res2 += y[it-1][i][k] * x[it-2][k][j] + x[it-1][i][k] * y[it-2][k][j];
					if(res2>1e15) res2 %= mod;
				}
				x[it][i][j] = res1 % mod;
				y[it][i][j] = res2 % mod;
			}
		}
	}
	ll sum = 0;
	for(int i = 0; i <= n; i++){
		sum = (sum + y[m][0][i]) % mod;
	}
	cout << sum << endl;
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