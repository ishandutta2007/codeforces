#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb emplace_back

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> a(n);
    vector<int> b(m);
    for (auto &c : a) {
        cin >> c;
    }
    for (auto &c : b) {
        cin >> c;
    }
    int i = 0, j = 0;
    while (a[i] % p == 0) i++;
    while (b[j] % p == 0) j++;
    cout << i + j;
    return 0;
}