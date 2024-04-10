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



int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    int n;
    cin >> n;
    if( n < 4){
        cout << "NO\n";
        return 0;
    }
    if( n % 2 == 0) {
        cout << "YES\n";
        int ones = 1;
        for(int i = n; i > 4; i-=2){
            cout << i << " - " << i - 1 << " = " << "1\n";
            ones++;
        }
        while( ones > 1){
            cout << "1 * 1 = 1\n";
            ones--;
        }
        cout << "1 * 2 = 2\n2 * 3 = 6\n6 * 4 = 24\n";
        return 0;
    }
        cout << "YES\n";
        int ones = 1;
        for(int i = n; i > 5; i-=2){
            cout << i << " - " << i - 1 << " = " << "1\n";
            ones++;
        }
        while( ones > 1){
            cout << "1 * 1 = 1\n";
            ones--;
        }
        cout << "3 + 4 = 7\n7 + 5 = 12\n1 * 2 = 2\n2 * 12 = 24\n";
        return 0;
    


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}