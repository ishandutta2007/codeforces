#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define forn2(i, n) for (i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int mod = 1000000007;

int p[100100];
int d[100100];

int main() {
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    forn (i, n) {
        cin >> p[i];
        d[i] = 1 + min(n - i - 1, k) + min(i, k);
        if (p[i] == 0) {
            continue;
        }
        --p[i];
        int j = p[i];
        d[i] += d[j];
        d[i] -= max(0, min(n, j + k + 1) - max(0, i - k));
    }
    forn (i, n) {
        cout << d[i] << " ";
    }
    return 0;
}