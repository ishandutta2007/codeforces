#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <complex> 
#include <ctime>
#include <cstring>
#include <stack>
#include <random>
 
using namespace std;
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

const double EPS = 1e-9;

long long ans = 0;
vector<set<int>> s(20);


void deleteBit(int k, long long i) {
    long long r = *(s[k].lower_bound(i));
    long long l = *(--s[k].lower_bound(i));
    ans -= (r - l - 1) * (r - l) / 2 * (long long)(1 << k);
    ans += (i - l - 1) * (i - l) / 2 * (long long)(1 << k);
    ans += (r - i - 1) * (r - i) / 2 * (long long)(1 << k);
    s[k].insert((int)i);
}

void addBit(int k, long long i) {
    s[k].erase((int)i);
    long long r = *(s[k].lower_bound(i));
    long long l = *(--s[k].lower_bound(i));
    ans += (r - l - 1) * (r - l) / 2 * (long long)(1 << k);
    ans -= (i - l - 1) * (i - l) / 2 * (long long)(1 << k);
    ans -= (r - i - 1) * (r - i) / 2 * (long long)(1 << k);
}

int main() {
    // freopen("input.txt", "r", stdin);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    
    for (int i = 0; i < 20; ++i) {
        s[i].insert(-1);
        s[i].insert(n);
    }

    vector<vector<int>> p(20, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        int k = a[i];
        for (int j = 0; j < 20; ++j, k /= 2) {
            p[j][i] = k & 1;
            if (!p[j][i])
                s[j].insert(i);
        }
    }

    for (int i = 0; i < 20; ++i) {
        long long cur = 0;
        for (int j = 0; j < n; ++j) {
            if (p[i][j]) 
                ++cur;

            if (!p[i][j] || j + 1 == n) {
                ans += cur * (cur + 1) / 2 * (long long)(1 << i);
                cur =  0;
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        int pos, val;
        cin >> pos >> val;
        --pos;

        for (int j = 0; j < 20 ; ++j, val /= 2) {
            int b = val & 1;

            if (p[j][pos] && !b) {
                deleteBit(j, pos);
                p[j][pos] = 0;
            }

            if (b && !p[j][pos]) {
                addBit(j, pos);
                p[j][pos] = 1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}