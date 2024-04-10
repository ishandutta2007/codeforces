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

string x;
int n, k;

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> k >> x;

    for(int i = 0; i < n && k > 0; ){
        if(x[i] != '4' || i + 1==n || x[i+1] != '7') {
            i++;
            continue;
        }

        if(i % 2 == 0){
            if(i + 2 < n && x[i+2] == '7'){
                k %= 2;
                if( k > 0 ) x[i+1] = '4';
            }
            else {
                x[i+1] = '4';
                i++;
            }
        }
        else {
            x[i] = '7';
            i--;
        }
        k--;
    }
    cout << x << endl;


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}