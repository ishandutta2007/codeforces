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
int x[100100];
int y[100100];
int a[100100];
int d[100100];
int cnt[100100];
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i <= n + 1; i++) d[i] = inf;
	d[0] = 0;
	for(int i = 0; i < n; i++) {
		x[i] = lower_bound(d, d + n + 1, a[i])-d;
		d[x[i]] = min(d[x[i]], a[i]);
	}
	
	for(int i = 0; i <= n + 1; i++) d[i] = inf;
	d[0] = 0;
	int mx = 0;
	for(int i =n-1; i >=0; i--) {
		y[i] = lower_bound(d, d + n + 1, 100100-a[i])-d;
		d[y[i]] = min(d[y[i]], 100100-a[i]);
		mx = max(mx, x[i] + y[i]);
	}
	for(int i = 0; i < n; i++) {
		if(x[i] + y[i] == mx) {
			cnt[x[i]]++;
		}
	}
	for(int i = 0; i < n; i++){
		if(x[i] + y[i] == mx) {
			if(cnt[x[i]] == 1) cout<<3;
			else cout << 2;
		}else cout << 1;
	}
	
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