#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> pos2[5000005];

void answer(int x, int y, int xx, int yy) {
    cout << "YES\n";
    cout << x + 1 << ' ' << y + 1 << ' ' << xx + 1 << ' ' << yy + 1 << '\n';
    exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }    

    for (int l = 1; l < n; l++) {
        for (int i = 0; i < n - l; i++) {
            int j = i + l;
            int sum = a[i] + a[j];
            for (auto &e : pos2[sum]) {
                if (i != e.first && i != e.second && j != e.first && j != e.second) answer(i, j, e.first, e.second);
            }
            pos2[sum].push_back({i, j});
        }
    }

    cout << "NO\n";

    return 0;
}