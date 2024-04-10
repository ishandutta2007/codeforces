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

string t[10];


int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    t[0]="qwertyuiop";
    t[1]="asdfghjkl;";
    t[2] = "zxcvbnm,./";
    map < char, pii > m;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < t[i].size(); j++){
            m[t[i][j]] = mp(i, j);
        }
    }
    string a, b;
    cin >> a >> b;
    int k = 1;
    if( a == "R"){
        k = -1;
    }
    for(int i = 0; i < b.size(); i++){
        cout << t[m[b[i]].f][m[b[i]].s + k];
    }
    cout << endl;


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}