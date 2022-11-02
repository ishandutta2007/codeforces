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
int n;
int m;
int a[100100];
vector<int> g[100100];

ll get(ll v, int k) {
	ll res = 1;
	while(k > 0) {
		if(k & 1) {
			res = res * v % mod;
		}
		v = v * v % mod;
		k >>= 1;
	}
	return res;
}
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		a[x]++;
	}
	for(int i = 1; i <= 100000; i++){
		for(int j = i;  j <= 100000; j+=i) {
			g[j].pb(i);
		}
	}
	for(int i = 1; i <= 100000; i++) a[i] += a[i-1];
	int ans = 0;
	for(int i = 1; i <= 100000; i++) {
		int cur = 1;
		for(int j = 0; j < g[i].size(); j++){
			if(g[i].size() == j + 1) {
				int s = a[100000] - a[g[i][j] - 1];
				cur = (cur * (get(j+1, s) - get(j, s) + mod)) % mod;
			}else{
				int s = a[g[i][j+1] - 1] - a[g[i][j] - 1];
				cur = cur * get(j+1, s) % mod;
			}
		}
		ans = (ans + cur) % mod;
	}
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