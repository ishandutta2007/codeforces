#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

void solve() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector <char> ans;
    int wins = 0;
    forn (i, 0, n) {
        char d;
        cin >> d;
        if (d == 'R') {
            if (b) {
                ans.pb('P');
                b--;
                wins++;
            } else {
                ans.pb('#');
            }
        } else if (d == 'P') {
            if (c) {
                ans.pb('S');
                c--;
                wins++;
            } else {
                ans.pb('#');
            }
        } else if (d == 'S') {
            if (a) {
                ans.pb('R');
                a--;
                wins++;
            } else {
                ans.pb('#');
            }
        }
    }/*
    for (char c : ans)
        cout << c;
    cout << "\n";*/
    if (wins >= (n + 1) / 2) {
        cout << "YES\n";
        for (char c : ans) {
            if (c != '#')
                cout << c;
            else {
                if (a) {
                    cout << 'R';
                    a--;
                } else if (b) {
                    cout << 'P';
                    b--;
                } else if (c) {
                    cout << 'S';
                    c--;
                }
            }
        }
    } else {
        cout << "NO";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}