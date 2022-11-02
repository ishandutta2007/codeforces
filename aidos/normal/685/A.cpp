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

int dp[12][2][1<<11];
int d[12][2][1<<11];
int n, m;
int a[111];
int b[111];

int get2(int pos, int sa, int mask){
	if(pos == m) {
		//if(sa) return 0;
		return 1;
	}
	int &res = d[pos][sa][mask];
	if(res != -1)return res;
	res = 0;
	if(sa){
		for(int i = 0; i < b[pos]; i++){
			if(mask & (1<<i)) continue;
			res += get2(pos + 1, 0, mask | (1<<i));
		}
		if(mask & (1<<b[pos])) {
		
		}else res += get2(pos+1, 1, mask | (1<<b[pos]));
	}
	else{
		for(int i = 0; i < 7; i++){
			if(mask & (1<<i)) continue;
			res += get2(pos + 1, 0, mask | (1<<i));
		}
	}
	return res;
}
int get(int pos, int sa, int mask){
	if(pos == n) {
		//if(sa) return 0;
		return get2(0, 1, mask);
	}
	int &res = dp[pos][sa][mask];
	if(res != -1)return res;
	res = 0;
	if(sa){
		for(int i = 0; i < a[pos]; i++){
			if(mask & (1<<i)) continue;
			res += get(pos + 1, 0, mask | (1<<i));
		}
		if(mask & (1<<a[pos])) {
		
		}else res += get(pos+1, 1, mask | (1<<a[pos]));
	}
	else{
		for(int i = 0; i < 7; i++){
			if(mask & (1<<i)) continue;
			res += get(pos + 1, 0, mask | (1<<i));
		}
	}
	return res;
}
void solve(){
	int x, y;
	cin >> x>> y;
	x--;
	if(x == 0) a[n++] = 0;
	while(x > 0){
		a[n++] = x % 7;
		x/=7;
	}
	y--;
	if(y==0) b[m++] = 0;
	while(y > 0){
		b[m++] = y % 7;
		y/=7;
	}
	reverse(a, a + n);
	reverse(b,b + m);
	memset(dp, -1, sizeof dp);

	memset(d, -1, sizeof d);
	cout <<get(0, 1, 0) << endl;
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Test case #%d\n", i);
      solve();
    }


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}