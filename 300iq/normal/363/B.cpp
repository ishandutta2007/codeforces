#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair

string s[10];

int main() {
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    vector <int> pref(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    pref[0] = a[0];
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i - 1] + a[i];
    }
    int ans = INT_MAX;
    int res = 0;
    for (int i = 0; i + k - 1 < n; i++) {
        ans = min(ans, pref[i + k - 1] - (i ? pref[i - 1] : 0));
        if (ans == pref[i + k - 1] - (i ? pref[i - 1] : 0)) {
            res = i;
        }
    }
    cout << res + 1 << endl;
}