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

int n, k;
map <int, int> lib;
int a[500000];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int64 res = 0;
    bool f = false;
    int curr = -1;

    for (int st = 0; st < n; ++st) {
        while (!f && curr < n) {
            ++curr;
            ++lib[a[curr]];
            if (lib[a[curr]] == k) {
                f = true;
            }
        }
        if (curr == n)
            break;
        else {
            res += int64(n - curr);
        }
        --lib[a[st]];
        if (lib[a[st]] == (k - 1))
            f = false;
    }
    cout << res << endl;
    return 0;
}