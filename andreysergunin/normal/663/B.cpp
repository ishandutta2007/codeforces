#include <string>
#include <queue>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <set>
#include <iostream>
#include <cassert>
#include <utility>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

int main() {
    int test;
    cin >> test;
    for (int t = 0; t < test; ++t) {
        string s;
        cin >> s;
        s = s.substr(4, sz(s) - 4);
        int n = sz(s);
        vector<long long> a(n);
        long long p = 1;
        a[0] = s[n - 1] - '0';
        for (int i = n - 2; i >= 0; --i) {
            p *= 10;
            a[n - i - 1] = a[n - i - 2] + p * (s[i] - '0');
        }
        
        vector<long long> b(n);
        b[0] = (a[0] == 9 ? 1989 : 1990 + a[0]);
        p = 10;
        for (int i = 1; i < n; ++i) {
            p *= 10;
            if (b[i - 1] < a[i])
                b[i] = a[i];
            else {
                if ((b[i - 1] / p) * p + a[i] > b[i - 1])
                    b[i] = (b[i - 1] / p) * p + a[i];
                else
                    b[i] = (b[i - 1] / p + 1) * p + a[i];
            }
        }
        cout << b[n - 1] << endl;
    }
    return 0;
}