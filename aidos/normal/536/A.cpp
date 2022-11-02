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
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;

int a, b, n;
ll sum[6000100];

bool check(int l, int r, int m, int t){
	if(r-l > m-1){
		if((sum[r] - sum[l-1] > t*1ll * m) || sum[r] - sum[r-1] > t) return 0;
		return 1;

	}
	return sum[r] - sum[r-1] <= t;
}

int get(int l, int t, int m){
	//if(sum[l] - sum[l-1] < t) return -1;
	int r1 = l;
	int r2 = 6000000;
	int res = -1;
	while(r1 <= r2){
		int mid = (r1 + r2) >> 1;
		if(check(l, mid, m, t)){
			res = mid;
			r1 = mid+1;
		}
		else r2 = mid-1;
	}

	return res;
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >>a >> b >> n;
    sum[1] = a;
    ll x = a;
    for(int i = 2; i <= 6000000; i++){
    	x += b;
    	sum[i] = sum[i-1] + x;

    }
    for(int i = 1, l, t, m; i <= n; i++){
    	cin >> l >> t >> m;
    	cout << get(l, t, m ) << endl;
    }



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}