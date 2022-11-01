#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = double;
using pii = pair<int, int>;
using vi = vector<int>;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define x first
#define y second
const int maxn = 1e6, mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    int n; cin >> n;
    vector<pii> a(n);
    for(int i = 0; i < n; i++) {
        int s = 0;
        for(int j = 0; j < 4; j++) { int x; cin >> x; s += x; }
        a[i] = {-s, i};
    }
    sort(all(a));
    for(int i = 0; i < n; i++) if(a[i].y == 0) cout << i + 1;
}