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

int n;
int a[200000];
int b[200000];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(a, a + n);
    int l = 0; 
    int r = n - 1;
    bool f = true;
    for (int i = 0; i < n; ++i)
        if (a[i] != b[i])
            f = false;
    if (f) {
        cout << "YES\n";
        return 0;
    }
    for (int i = 0; i < n; ++i)
        if (a[i] != b[i]) {
            l = i;
            break;
        }
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] != b[i]) {
            r = i;
            break;
        }
    }
    swap(b[l], b[r]);
    f = true;
    for (int i = 0; i < n; ++i)
        if (a[i] != b[i]) 
            f = false;
    if (f) {
        cout << "YES\n";
        return 0;
    }
    else {
        cout << "NO\n";
    }
    return 0;
}