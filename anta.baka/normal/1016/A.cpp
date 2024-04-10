#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
using ll = long long;
const int maxn = 1e6, INF = 1e9;
using ld = double;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    int n, m; cin >> n >> m;
    int cur = 0;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(x < m - cur) cout << 0 << ' ';
        else cout << 1 + (x - (m - cur)) / m << ' ';
        cur = (cur + x) % m;
    }
}