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
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define Vint vector < int >
#define Vll vector < ll >
#define Vb vector < bool >
#define Vpii vector < pii >
#define Vpll vector < pll >

const int inf = (1ll << 31) - 1;

#define MAXN (int) (1e7)
using namespace std;

int n, a[111000], m;
ll cnt[111000], sum[111000];
ll cntx = 0;
ll maxn = 0;
vector  < int > v[111000];
int main () {
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif           
    cin >> n >> m;
    for(int i = 0; i < m; i++){
    	cin >> a[i];
    	a[i]--;
    }
    for(int i = 0; i < m; i++){
    	if(i){
    		cnt[a[i]] += abs(a[i] - a[i-1]);
    		cntx += abs(a[i] - a[i-1]);
    		if(a[i]!= a[i-1])v[a[i]].pb(a[i-1]);
    	}
    	if(i+1 < m){
    		cnt[a[i]] += abs(a[i+1] - a[i]);
    		if(a[i+1] != a[i] ) v[a[i]].pb(a[i+1]);
    	}
    }
    maxn = cntx;
//    cout << cntx << endl;
    for(int i = 0; i < n; i++){
    	sort(v[i].begin(), v[i].end());
    	ll gg = (ll)1e18;
    	for(int j = 0; j < v[i].size(); j++){
    		if(j) sum[j] = sum[j-1] + v[i][j];
    		else sum[j] = v[i][j];
    	}
    	int tt = v[i].size();
    	for(int j = 0; j < tt; j++){
    		gg = min(gg, j * 1ll * v[i][j]-(sum[j] - v[i][j]) + sum[tt-1] - sum[j] - (tt - j - 1) * 1ll* v[i][j]);
    	}
//    	cout << i << " " << gg << " " << cnt[i] << endl;
    	ll dd = cntx - cnt[i] + gg;
    	if( dd < maxn) maxn = dd;
    }
    cout << maxn << endl;
	#ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
    return 0;
}