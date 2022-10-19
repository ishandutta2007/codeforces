#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

bool b[100];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vector<string> v;
    v.pb(" ");
    for (char i = 'A'; i <= 'Z'; i++) {
        for (char j = 'a'; j <= 'z'; j++) {
            string s;
            s.pb(i);
            s.pb(j);
            v.pb(s);
        }
    }
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n - k + 1; i++) {
        string s;
        cin >> s;
        if (s == "YES") b[i] = 1;
        else b[i] = 0;
    }
    string res[100];
    for (int i = 1; i < k; i++) {
        res[i] = v[i];
    }
    for (int i = 1; i <= n - k + 1; i++) {
        if (b[i] == 1) {
            res[i + k - 1] = v[i + k - 1];
        } else res[i + k - 1] = res[i];
    }
    for (int i = 1; i <= n; i++) {
        cout << res[i] << ' ';
    }
    return 0;
}