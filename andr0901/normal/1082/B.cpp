#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    s += '#';
    vector <int> v;
    int l = 1;
    int cnt = 0;
    //cout << s;
    forn (i, 1, n + 1) {
        if (s[i] != s[i - 1]) {
            if (s[i - 1] == 'G') {
                v.pb(l);
                cnt++;
            }
            else
                v.pb((-1) * l);
            l = 1;
        } else {
            l++;
        }
    }
    int ans = 0;
    for (int i = 1; i + 1 < v.size(); i++) {
        if (v[i] == -1) {
            if (cnt > 2) {
                ans = max(ans, v[i - 1] + v[i + 1] + 1);
            } else {
                ans = max(ans, v[i - 1] + v[i + 1]);
            }
        }
    }
    forn (i, 0, v.size()) {
        if (cnt > 1)
            ans = max(ans, v[i] + 1);
        else
            ans = max(ans, v[i]);
    }/*
    forn (i, 0, v.size())
        cout << v[i] << " ";
    cout << "\n";*/
    cout << ans;
    return 0;
}