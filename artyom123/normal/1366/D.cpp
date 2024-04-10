#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int MAXN = 1e7 + 5;

int e[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    for (ll i = 2; i < MAXN; i++) {
        if (e[i] != 0) continue;
        e[i] = i;
        for (ll j = i * i; j < MAXN; j += i) {
            if (e[j] == 0) e[j] = i;
        }
    }
    vector<int> d1(n, -1), d2(n, -1);
    for (int i = 0; i < n; i++) {
        ll tmp = e[a[i]];
        while (a[i] % (tmp * e[a[i]]) == 0) tmp *= e[a[i]];
        if (tmp == a[i]) continue;
        d1[i] = tmp, d2[i] = a[i] / tmp;
    }
    for (auto &c : d1) cout << c << " ";
    cout << "\n";
    for (auto &c : d2) cout << c << " ";
    return 0;
}