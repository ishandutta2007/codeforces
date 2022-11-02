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
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define Vint vector < int >
#define Vll vector < ll >
#define Vb vector < bool >
#define Vpii vector < pii >
#define Vpll vector < pll >

const int inf = (1ll << 31) - 1;

#define MAXN (int) (1e7)
using namespace std;

int main () {
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    int a[10];
    for(int i = 1; i <= 4; i++){
        cin >> a[i];
    }
    string s;
    cin >> s;
    int sum  =0;
    for(int i = 0; i < s.size(); i++){
        sum += a[s[i] - '0'];
    }
    cout << sum << endl;
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}