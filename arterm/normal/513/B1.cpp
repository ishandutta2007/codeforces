#include <bits/stdc++.h>

using namespace std;

#define long long long

int main() {
    long m, n;
    cin >> n >> m;
    vector<int> l, r;
    for (long i = n - 2; i >= 0; --i)
        if ((1ll << i) < m) {
            r.push_back(n - i - 1);
            m -= (1ll << i);
        } else
            l.push_back(n - i - 1);
    l.push_back(n);
    reverse(r.begin(), r.end());
    for (auto x : l)
        cout << x << " ";
    for (auto x : r)
        cout << x << " ";
    cout << "\n";
    return 0;
}