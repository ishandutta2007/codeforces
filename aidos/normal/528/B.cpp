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

int t[1000100];
pii a[200100];
int sum[200100];
int n, m, k;

int get_low(int x){
	int l = 0;
	int r = k-1;
	int ans = -1;
	while(l<=r){
		int mid = (l+r)>>1;
		if(sum[mid] <= x) {
			l = mid+1;
			ans = mid;
		}
		else r = mid-1;
	}
	return ans;
}

int get_max(int v, int tl, int tr, int l, int r){
	if(l > r) return -1000000;
	if(l == tl && tr == r) return t[v];
	int mid = (tl + tr) >> 1;
	return max(get_max(2 *v, tl, mid, l, min(r, mid)), get_max(2 *v + 1, mid+1, tr, max(mid+1, l), r));
}


void update(int v, int tl, int tr, int pos, int val){
	if(tl == tr){
		t[v] = max(val, t[v]);
		return;
	}
	int mid = (tl + tr) >> 1;
	if(pos <= mid) update(v*2, tl, mid, pos, val);
	else update(v*2+1, mid+1, tr, pos, val);
	t[v] = max(t[v*2], t[v*2+1]);
}




int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
    	scanf("%d %d", &a[i].f, &a[i].s);
    	sum[i] = a[i].f + a[i].s;
    }
    for(int i = 0; i < 1000010; i++)
    	t[i] = -1000000;
    sort(sum, sum+n);
    k = unique(sum, sum + n) - sum;
    sort(a, a + n);
    int ans = 1;
    for(int i = 0; i < n; i++){
		int pos = get_low(a[i].f - a[i].s);
		int ansx = get_max(1, 0, k-1, 0, pos);
		//cout << 
		//cout << ansx<< endl;
		if(ansx<0) ansx = 0;
		ansx++;

		pos = get_low(a[i].f+a[i].s);
		
		update(1, 0, k-1, pos, ansx);
		ans = max(ans, ansx);
	}

	cout << ans << endl;

    

    



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}