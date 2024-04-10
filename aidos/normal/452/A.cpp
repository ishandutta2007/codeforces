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
string ss[] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon","sylveon"};
int main () {
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    string k;
    cin >> k;
    for(int i = 0; ; i++){
        int ok  =1;
        if( ss[i].size() != n) continue;
        for(int j = 0; j < n; j++){
            if( ss[i][j] == k[j] || k[j] == '.') continue;
            ok  = 0;
        }
        if( ok) {
            cout << ss[i] << endl;
            return 0;
        }
    }
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}