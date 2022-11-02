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


int n;
int a[200200];
int sp[20][200200];
int tw[200200];
void precalc(){
	tw[0] = -1;
	for(int i =1; i<=200010; i++){
		tw[i] = tw[i/2] + 1;
	}
	for(int i = 0; i < n; i++)
		sp[0][i] = a[i];
	for(int i = 1; (1<<i) <= n; i++){
		for(int j = 0; j + (1 << i ) <= n; j++){
			sp[i][j] = max(sp[i-1][j], sp[i-1][j + (1<< (i-1))]);
		}
	}
}

vector<int> t[4*300300];
 
void build (int v, int tl, int tr) {
	if (tl == tr)
		t[v] = vector<int> (1, a[tl]);
	else {
		int tm = (tl + tr) / 2;
		build (v*2, tl, tm);
		build (v*2+1, tm+1, tr);
		merge (t[v*2].begin(), t[v*2].end(), t[v*2+1].begin(), t[v*2+1].end(),
			back_inserter (t[v]));
	}
}

int get_max(int l, int r){
	int len = tw[r-l+1];
	return max(sp[len][l], sp[len][r- (1<<len)+1]);

}

int query (int v, int tl, int tr, int l, int r, int x) {
	if (l > r)
		return 0;
	if (l == tl && tr == r) {
		vector<int>::iterator pos = lower_bound (t[v].begin(), t[v].end(), x);
		return t[v].size() - (pos - t[v].begin());
	}
	int tm = (tl + tr) / 2;
	return query (v*2, tl, tm, l, min(r,tm), x)+query (v*2+1, tm+1, tr, max(l,tm+1), r, x);
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
    	scanf("%d", &a[i]);
    }

    build(1, 0, n-1);

    for(int i = 1; i < n; i++){
    	int ans=0;
    	int cnt = 0;
    	for(int j = 1; j < n; j+=i){
    		ans += query(1, 0, n-1, j, min(j+i-1, n-1), a[cnt]);
    		cnt++;
    	}
    	cout << n - ans - 1 << " ";
    }





    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}