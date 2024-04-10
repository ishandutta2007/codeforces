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
int a[200200];
int n;
int z;
int l = 0;
int u[200200];
int p[200200];
int b[200200];
int ok(int len) {
	int l = len;
	for(int i = 0; i < len; i++){
		while(l < n && a[l] - a[i] < z) l++;
		if(l == n) return 0;
		l++;
	}
	return 1;
}
void solve(){
	scanf("%d%d", &n, &z);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	int l = 1, r = n/2;
	int ans = 0;
	while(l <= r) {
		int mid =(l+r)/2;
		if(ok(mid)) ans = mid, l = mid+1;
		else r = mid-1;
	}
	cout << ans ;
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