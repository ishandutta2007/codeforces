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
int n, d,a[111], c = 0;

int main () {
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    cin >> n >> d;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    for(int i =0; i < n; i++){
        if( d < a[i] ){
            cout << -1;
            return 0;
        }
        d-=a[i];
        d-=10;
        c+=2;
    }
    while(d < 0 ){
        d+=5;
        c--;
    }
    while( d >= 5){
        d-=5;
        c++;
    }
    cout << c << endl;
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}