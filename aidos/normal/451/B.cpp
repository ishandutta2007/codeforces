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

#define MAXN (int) (1e5) + 10
using namespace std;

int n;
int a[MAXN];
int b[MAXN];

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[i]  = a[i];
    }
    sort(b, b + n);
    int l = 0, r = n-1;
    while( l < n && a[l] == b[l] ) l++;
    while( r >= 0 && a[r] == b[r]) r--;
    if( l > r ){
        cout << "yes\n1 1\n";
        return 0;
    }
    
    reverse(a+l, a + r + 1);
    for(int i = 0; i < n; i++){
        if( a[i] != b[i]){
            cout << "no\n";
            return 0;
        }
    }
    cout << "yes\n" << l+1 << " " << r+1 << endl;

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}