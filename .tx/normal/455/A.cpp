#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define foi(n) for (int i = 0; i < n; i++)
#define foj(n) for (int j = 0; j < n; j++)
#define fo(i, n) for (int i = 0; i < n; i++)
#define vei vector<int>
#define pii pair<int, int>
#define mp make_pair
#define fs first
#define sc second
#define null NULL

typedef long long ll;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vei a(1e5 + 1);
    foi(n) {
        int x;
        cin >> x;
        a[x]++;
    }
    vector<ll> d(a.size());
    d[1] = a[1];
    for (ll i = 2; i < a.size(); i++) {
        d[i] = max(d[i - 1], d[i - 2] + a[i] * i);
    }
    cout << *d.rbegin();
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}