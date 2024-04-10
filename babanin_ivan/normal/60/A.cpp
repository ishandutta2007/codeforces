#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define sec second
#define y1 botva23
typedef long long int64;
typedef long double ld;

const int inf = 2000000000;
const ld eps = 1e-07;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    int l = 1;
    int r = n;
    for (int i = 0; i < m; ++i) {
        string s1, s2, s3, s4;
        int t;
        cin >> s1 >> s2 >> s3 >> s4 >> t;
        if (s3[0] == 'l') {
            r = min(t - 1, r);
        }
        else {
            l = max(l, t + 1);
        }
    }
    if (l > r)
        cout << -1 << endl;
    else cout << r - l + 1 << endl;
    return 0;
}