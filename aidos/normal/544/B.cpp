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

char a[111][111];
int n, k;


int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        for(int j=0; j < n; j++){
            if(k > 0 && i % 2 == j % 2) {
                k--;
                a[i][j] = 'L';
            }
            else a[i][j] = 'S';
        }
    }

    if(k > 0){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)cout << a[i][j];
        cout << endl;
    }



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}