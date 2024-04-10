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

#define MAXN (int) (1e5)  + 10
using namespace std;

pii b[MAXN];

    vector <int> v[3];
int n;


int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> b[i].f;
        b[i].s = i;
    }
    sort(b, b + n);
    for(int i = 0; i < n; i++){
        v[i % 2].pb( b[i].s+1);
    }
    for(int j = 0; j < 2; j++){
        cout << v[j].size() << endl;
        for(int i = 0; i < v[j].size(); i++){
            cout << v[j][i] << " " ;
        }
        cout << endl;
    }


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}