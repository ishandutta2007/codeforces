#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve1(int n, vector <ll>& a) {
    if (n == 1) {
        cout << 1 << " " << 1 << "\n" << -a[0] << "\n";
        for (int i = 0; i < 2; ++i) cout << 1 << " " << 1 << "\n" << 0 << "\n";
        return;
    }
    cout << 1 << " " << 1 << "\n";
    cout << -a[0] << "\n";
    cout << 2 << " " << n << "\n";
    a[0] = 0;
    ll flex = -1;
    for (int i = 0; i < n; ++i) {
        if (((ll)(n - 1) * (ll)i) % n == 1) flex = i;
    }
    assert(flex != -1);
    for (int i = 1; i < n; ++i) {
        ll delta = (ll)(n - 1) * (ll)flex * (ll)(n - a[i] % n);
        cout << delta << " ";
        a[i] += delta;
    }
    cout << "\n" << 1 << " " << n << "\n";
    for (int i = 0; i < n; ++i) {
        cout << -a[i] << " ";
    }
}

int solve2() {

}

signed main (){
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int n;
        cin >> n;
        vector <ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        solve1(n, a);
    }
    else {
        int t;
        cin >> t;
        while (t--) {
            int n = rand() % 1000000;
            vector <ll> a(n);
            for (int i = 0; i < n; ++i) {
                a[i] = rand();
            }
            solve1(n, a);
        }
    }
}