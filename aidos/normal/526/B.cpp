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


int a[5050];

int n;
int x;
int y;

pii dfs(int c){
	if(c >= y) return mp(0,0);
	pii ff = dfs(c*2);
	pii ss = dfs(c*2+1);
	ff.f += a[c*2];
	ss.f += a[c*2+1];
	if(ff.f > ss.f){
		return mp(ff.f, ff.s + ss.s + ff.f - ss.f);
	}

	return mp(ss.f, ff.s + ss.s + ss.f - ff.f);
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

	cin >> n;
	x = (1 << (n+1)) - 1;
	for(int i = 2; i <= x; i++){
		cin >> a[i];
	}
	y = (1<<n);

	pii d = dfs(1);
	cout << d.s << endl;


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}