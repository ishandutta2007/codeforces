#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define test(args...) abc("[" + string(#args) + "]", args)
void abc() {cerr << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cerr << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    while (l != r) cout << *l << " \n"[++l == r];
}
const int mod = 1e9 + 7, N = 5001, logN = 20, K = 111;

void solve() {
    string s;
    cin >> s;
    vector <int> cnt(26, 0);
    for (char c : s) cnt[c - 'a']++;
    int type = 26 - count(all(cnt), 0);
    if (type == 1) {
        cout << s << endl;
        return;
    }
    int p = -1;
    for (int i = 0; i < 26; ++i) if (cnt[i] == 1) {
        p = i;
        break;
    }
    if (p != -1) {
        cout << char(p + 'a');
        for (int i = 0; i < 26; ++i) if (i != p) {
            cout << string(cnt[i], 'a' + i);
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < 26; ++i) if (cnt[i]) {
        p = i;
        break;
    }
    int n = s.length();
    if (cnt[p] - 2 <= (n - 2) / 2) {
        cout << char('a' + p) << char('a' + p);
        cnt[p] -= 2;
        for (int i = 0; i < n - 2; ++i) {
            if (i & 1 ^ 1) {
                for (int j = 0; j < 26; ++j) if (cnt[j] && j != p) {
                    cout << char('a' + j);
                    cnt[j]--;
                    break;
                }
            } else {
                if (cnt[p]) {
                    cout << char('a' + p);
                    cnt[p]--;
                } else {
                    for (int j = 0; j < 26; ++j) if (cnt[j]) {
                        cout << char('a' + j);
                        cnt[j]--;
                        break;
                    }
                }
            }
        }
        cout << endl;
    } else {
        if (type == 2) {
            int q;
            for (int i = 25; ~i; --i) if (cnt[i]) {
                q = i;
                break;
            }
            cout << char('a' + p) << string(cnt[q], 'a' + q) << string(cnt[p] - 1, 'a' + p) << endl;
        } else {
            int q, r;
            for (int i = 0; i < 26; ++i) if (cnt[i] && i != p) {
                q = i;
                break;
            }
            for (int i = 0; i < 26; ++i) if (cnt[i] && i != p && i != q) {
                r = i;
                break;
            }
            cout << char('a' + p) << char('a' + q) << string(cnt[p] - 1, 'a' + p) << char('a' + r);
            cnt[p] = 0, cnt[q]--, cnt[r]--;
            for (int i = 0; i < 26; ++i) if (i != p) {
                cout << string(cnt[i], 'a' + i);
            }
            cout << endl;
        }
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}