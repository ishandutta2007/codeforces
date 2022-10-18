#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int mod = 1000000007;

int x[100100];
int d[100100];

int main() {
    int n, k;
    cin >> n >> k;
    forn (i, n) {
        cin >> x[i];
    }
    d[0] = 0;
    for (int i = 1; i < n; ++i) {
        int j = lower_bound(x, x + n, x[i] - k) - x;
        if (i == j) {
            cout << -1 << endl;
            return 0;
        }
        d[i] = d[j] + 1;
    }
    cout << d[n - 1] << endl;
    return 0;
}