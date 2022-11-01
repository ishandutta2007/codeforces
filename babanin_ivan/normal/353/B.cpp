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

pair <int, int> a[1000];
int res[300];
int sum1, sum2;
int n1, n2;
vector <int> b[300];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> a[i].fir;
        a[i].sec = i;
        b[a[i].fir].pb(a[i].second);
    }
    //int last = 0;
    for (int i = 0; i < 100; ++i) {
        if (b[i].size()) {
            if (b[i].size() == 1) {
                if (sum1 < sum2) {
                    ++sum1;
                    res[b[i][0]] = 1;
                    ++n1;
                }
                else {
                    ++n2;
                    ++sum2;
                    res[b[i][0]] = 2;
                }
            }
            if (b[i].size() >= 2) {
                ++sum1;
                ++sum2;
                ++n1;
                ++n2;
                res[b[i][0]] = 1;
                res[b[i][1]] = 2;
            }
        }
    }
    //sort(a, a + 2 * n);
    cout << sum1 * sum2 << endl;
    for (int i = 0; i < 2 * n; ++i) {
        if (res[i])
            continue;
        if (n1 < n) {
            res[i] = 1;
            ++n1;
        }
        else {
            res[i] = 2;
            ++n2;   
        }
    }
    for (int i = 0; i < 2 * n; ++i)
        cout << res[i] << " ";
    return 0;
}