#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 1;
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector <pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].fi;
        if (a[i].fi >= 0) {
            a[i].fi = -a[i].fi - 1;
        }
        a[i].se = i;
    }
    sort(a.begin(), a.end());
    vector <int> b(n);
    if (n % 2 == 0) {
        for (auto &c : a) {
            b[c.se] = c.fi;
        }
    }
    else {
        a[0].fi = -a[0].fi - 1;
        for (auto &c : a) {
            b[c.se] = c.fi;
        }
    }
    for (auto &c : b) {
        cout << c << " ";
    }
    return 0;
}