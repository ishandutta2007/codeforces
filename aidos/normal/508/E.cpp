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
const int maxn = (int)1e3 + 10; //maximum + 10
const int mod = (int) 1e9 + 7;
using namespace std;

int n;
int L[maxn];
int R[maxn];
int dp[maxn][maxn];

int get(int l, int r) {
	if(r < l) return 1;
	int &res = dp[l][r];
	if(res != -1) return res;
	res = 0;
	if((r-l) * 2 + 1>= L[l] && (r-l) * 2 + 1 <= R[l])
		res = get(l+1, r);
	for(int m = l; m < r; m++) {
		res |= (get(l, m) & get(m+1, r));
	}
	return res;
}
void rec(int l, int r) {
	if(r < l) return;
	if((r-l) * 2 + 1>= L[l] && (r-l) * 2 + 1 <= R[l]) {
		if(get(l+1, r)) {
			cout << "(";
			rec(l+1, r);
			cout << ")";
			return;
		}
	}
	for(int m = l; m < r; m++) {
		if((get(l, m) & get(m+1, r))) {
			rec(l, m);
			rec(m+1, r);
			return;
		}
	}
}
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> L[i] >> R[i];
	}
	memset(dp, -1, sizeof dp);
	if(get(0, n-1)) {
		rec(0, n-1);
	} else {
		cout << "IMPOSSIBLE\n";
	}
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