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

int a[30];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int k;
    scanf("%d ", &k);
    string s;
    string res;
    getline(cin, s);
    for (int i = 0; i < s.size(); ++i)
        ++a[int(s[i] - 'a')];
    bool f = true;
    for (int i = 0; i < 26; ++i) {
        if (a[i] % k)
            f = false;
        for (int j = 0; j < a[i] / k; ++j)
            res.pb(char(i + 'a'));
    }
    if (!f)
        cout << -1 << endl;
    else {
        for (int i = 0; i < k; ++i)
            cout << res;
        cout << endl;
    }
    return 0;
}