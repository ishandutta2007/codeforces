#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

long long a[8][3];
bool f = false;

long long sqr(long long a) {
    return a * a;
}

long long dist(int i, int j) {
    return sqr(a[i][0] - a[j][0]) + sqr(a[i][1] - a[j][1]) + sqr(a[i][2] - a[j][2]);
}

void solve() {
    if (f)
        return;
    long long m = -1;
    for (int i = 0; i < 8; i++) {
        vector<long long> d;
        long long cur = 1e18;
        for (int j = 0; j < 8; j++)
            if (i != j) {
                d.push_back(dist(i, j));
                cur = min(d.back(), cur);
            }
        if (cur == 0)
            return;
        int c[4];
        for (int i = 1; i < 4; i++)
            c[i] = 0;
        for (int j = 0; j < 7; j++)
            if (d[j] % cur == 0 && d[j] / cur < 4)
                c[d[j] / cur]++;
        if (!(c[1] == 3 && c[2] == 3 && c[3] == 1 && (m == -1 || m == cur)))
            return;
        m = cur;
    }
    f = true;
    cout << "YES" << endl;
    for (int i = 0; i < 8; i++)
        cout << a[i][0] << " " << a[i][1] << " " << a[i][2] << endl;
}

void en(int k) {
    if (k == 8) {
        solve();
        return;
    }
    for (int i = 0; i < 6; i++) {
        next_permutation(a[k], a[k] + 3);
        en(k + 1);
    }
}

int main() {
    for (int i = 0; i < 8; i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    en(1);
    if (!f)
        cout << "NO";
    return 0;
}