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
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;

#define MAXN (int) (1e7)
using namespace std;
int n;
int b[200222];
int main () {
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    sort(b, b+n);

    if( b[n-1] != b[0]){
        int k = 0, l = n-1;
        while( b[k] == b[0]) k++;
        while( b[l] == b[n-1]) l--;
        cout << b[n-1] - b[0] << " " << k * 1ll * (n - l - 1) << endl;
    }
    else {
        cout << 0 << " " << n * 1ll * ( n - 1) / 2 << endl;
    }
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}