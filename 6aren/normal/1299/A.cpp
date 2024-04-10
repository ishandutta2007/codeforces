#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x>>y)&1)

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vi a(n + 1);
    vector<vi> v(65);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 61; j >= 0; j--) {
            if (bit(a[i], j)) v[j].pb(i);
        }
    }
    int pivot = 0;
    for (int i = 61; i >= 0; i--) {
        if (v[i].size() == 1) {
            pivot = v[i][0];
            break;
        }
    }
    if (pivot == 0) {
        for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    } else {
        cout << a[pivot] << ' ';
        for (int i = 1; i <= n; i++) {
            if (i != pivot) cout << a[i] << ' ';
        }
    }
    return 0;
}