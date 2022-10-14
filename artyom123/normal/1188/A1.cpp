#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int m = n - 1;
    vector<int> deg(n);
    while (m--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        deg[a]++;
        deg[b]++;
    }
    for (auto &c : deg) {
        if (c == 2) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}