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
int b[100100], x[100100], a[100100], y[100100];
int main () {
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> x[i] >> y[i];
    	a[x[i]]++;
    	b[y[i]]++;
    }
    for(int i = 0; i<n; i++){
    	int c1 = 0, c2 = 0;
    	c1 = n-1;
    	c2 = n - 1 - a[y[i]];
    	c1 += a[y[i]];
    	cout << c1 << " "<< c2 << endl;
    }
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
    return 0;
}