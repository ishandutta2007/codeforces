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
set < int > S;
int w[200200];
int h[200200];
int a[200200];
    


int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i++){
    	cin >> w[i] >> h[i];
    	a[i] = h[i];
    	sum += w[i];
    }
    sort(a, a+n);
    for(int i = 0; i < n; i++){
    	if(h[i] == a[n-1]){
    		cout << (sum - w[i] ) * a[n-2] << " ";
    	}
    	else cout << (sum - w[i]) * a[n-1] << " ";
    }








    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}