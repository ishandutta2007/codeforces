
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = (int)1e6 + 10;
int n, m, k;

void solve() {
    cin >> n;
    vector < tuple<int, int, int> > a;
    ll s1 = 0, s2 = 0;
    for(int i = 1; i <= 2*n-1; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back({x, y, i});
        s1 += x;
        s2 += y;
    }
    sort(a.begin(), a.end());
    ll x = 0, y = 0;
    vector<int> b, c;
    for(int i = 0; i < 2*n-1; i++) {
        if(i%2) {
            y += get<1>(a[i]);
            b.push_back(get<2>(a[i]));
        } else {
            x += get<1>(a[i]);
            c.push_back(get<2>(a[i]));
        }
    }
    y += get<1>(a[2*n-2]);
    b.push_back(get<2>(a[2*n-2]));
    if(x >= y) {
        swap(b, c);
    }
    cout << "YES\n";
    for(int x: b) cout << x << " " ;
    cout << "\n";
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin >> t;
    for(int i=1; i <= t; i++) {
        solve();
    }
    return 0;
}