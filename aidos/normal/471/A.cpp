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

#define MAXN (int) (1e7)
using namespace std;

int n = 6;
int a[11];


int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    do{
        int i = 0;
        if( a[i] == a[i+1] && a[i+1]==a[i+2] && a[i + 2] == a[i+3]){
            if(a[i+4]==a[i+5]){
                cout << "Elephant";
            }
            else cout << "Bear";
            return 0;
        }
    }
    while(next_permutation(a, a + n));
    cout << "Alien";
    
    

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}