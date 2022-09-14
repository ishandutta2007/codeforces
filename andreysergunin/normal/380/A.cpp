#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <ctime>
#include <queue>

using namespace std;

const long long MAXC = 1e6;

int main() {
    int n, m;
    cin >> m;
    vector<long long> t(m), x(m), c(m);
    for (int i = 0; i < m; i++) {
        cin >> t[i];
        cin >> x[i];
        if (t[i] == 2)
            cin >> c[i];
    }
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    long long k = 0;
    int l = 0;
    vector<long long> p;
    for (int i = 0; i < m; i++) {
        if (t[i] == 1) {
            if (k < MAXC)
                p.push_back(x[i]);
            k++;
            if (l < n && a[l] == k) {
                cout << x[i] << " ";
                ++l;
            }
        }
        else {
            while (l < n && k + c[i] * x[i] >= a[l]) {
                cout << p[(a[l] - k - 1 + x[i]) % x[i]] << " ";
                ++l;
            }
            long long k1 = k + x[i] * c[i];
            if (k < MAXC) {
                bool f = false;
                for (int j = 0; j < c[i]; j++) {
                    for (int q = 0; q < x[i]; q++) {
                        p.push_back(p[q]);
                        ++k;
                        if (k >= MAXC) {
                            f = true;
                            break;
                        }
                    }
                    if (f)
                        break;
                }
            }
            k = k1;
        }
    }
    return 0;
}