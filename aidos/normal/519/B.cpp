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
int a[100100];
int b[100100];
int c[100100];

int get(int *a, int *b, int m){
	for(int i = 0; i < m; i++){
		if(a[i] != b[i]) return a[i];
	}
	return a[m];
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i<n-1; i++) cin >> b[i];
    for(int i = 0; i < n-2; i++) cin >> c[i];
    sort(a, a+n);
    sort(b, b+n-1);
    sort(c, c+n-2);
    cout << get(a, b, n-1) << endl << get(b, c, n-2) << endl;




    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}