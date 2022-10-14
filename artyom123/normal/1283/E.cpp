#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> usd(n + 2);
    vector<int> x(n);
    for (auto &c : x) cin >> c;
    sort(all(x));
    int MX = 0;
    for (auto &c : x) {
        if (!usd[c - 1]) {
            MX++;
            usd[c - 1] = 1;
            continue;
        }
        if (!usd[c]) {
            MX++;
            usd[c] = 1;
            continue;
        }
        if (!usd[c + 1]) {
            MX++;
            usd[c + 1] = 1;
        }
    }
    int MN = 0;
    usd.assign(n + 2, 0);
    for (auto &c : x) {
        if (usd[c - 1] || usd[c] || usd[c + 1]) {
            continue;
        }
        usd[c + 1] = 1;
        MN++;
    }
    cout << MN << " " << MX;
    return 0;
}