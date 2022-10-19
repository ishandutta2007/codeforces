#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

int a[100005];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n, x;
        set<int> s;
        cin >> n >> x;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            s.insert(a[i]);
        }
        sort(a + 1, a + n + 1);
        int mx = a[n];
        int ans = 0;
        if (x > mx) {
            ans = x / mx + 1;
            if (x % mx == 0) ans--;
        } else {
            if (s.count(x)) ans = 1;
            else ans = 2;
        }
        cout << ans << '\n';
    }
    return 0;
}