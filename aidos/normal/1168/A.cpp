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
int n, m;
int a[300300];
int b[300300];
int can(int x){
	int last = 0;
	for(int i = 0; i < n; i++){
		if(a[i] + x < last) return 0;
		int z = (a[i] + x) % m;
		if(z < last) {
			b[i] = max(last, a[i]);
		}else if(a[i] + x >= m) {
			b[i] = last;
		}
		else b[i] = max(a[i], last);
		last = b[i];
	}
	return 1;
}
void solve(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	int l = 0, r = m;
	int res = -1;
	while(l <= r){
		int mid = (l + r)>>1;
		if(can(mid)) {
			r = mid-1;
			res = mid;
		}else l = mid+1;
	}
	cout << res << "\n";
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