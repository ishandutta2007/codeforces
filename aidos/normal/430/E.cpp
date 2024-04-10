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
int n, m;
int a[25];
int b[25];
int dp[13][1<<13][24];

int get(int p, int mask, int c) {
	if(p == m) {
		return mask == (1<<(m-1)) &&c == 0;
	}
	int &res = dp[p][mask][c];
	if(res != -1) return res;
	res =  0;
	for(int h = mask; ; h = ((h-1)&mask)) {
		int d = b[p] - 1;
		for(int i = 0; i < p; i++) {
			if(h&(1<<i)) {
				if(b[i] + 1 == b[p]) d = -1;
				d -= b[i];
			}
		}
		if(c >= d && d >= 0) {
			res |= get(p+1, (mask^h)|(1<<p), c-d);
		}
		if(h==0) break;
	}
	return res;
}
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[x]++;
	}
	if(n == 1) {
		cout << "YES\n";
		return;
	}
	
	if(a[1] * 2 < n+1) {
		cout << "NO\n";
		return;
	}
	if(a[1] < 2 || a[n] != 1 || a[2] > 0) {
		cout << "NO\n";
		return;
	}
	if(a[n-1] > 0) {
		cout << "NO\n";
		return;
	}
	m = 0;
	for(int i = 2; i <= n; i++){
		for(int j = 0; j < a[i]; j++) b[m++] = i;
	}
	memset(dp, -1, sizeof dp);
	if(get(0, 0, a[1])) {
		cout << "YES\n";
	}
	else cout << "NO\n";
	
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