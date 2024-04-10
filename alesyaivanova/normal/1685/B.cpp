#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 2e5 + 9;
vector<int> len[4];
int s[maxn];

void update(int q, int& c) {
    if (!c) {
        return;
    }
    for (int i = 0; i < len[q].size(); i++) {
        if (c <= len[q][i] / 2) {
            len[q][i] -= c * 2;
            c = 0;
            break;
        } else {
            c -= len[q][i] / 2;
            len[q][i] = 0;
        }
    }
}

void solve() {
    int a, b, c, d;
    string ss;
    cin >> a >> b >> c >> d >> ss;
    int n = ss.size();
    int cnt_0 = 0, cnt_1 = 0;
    for (int i = 0; i < n; i++) {
        s[i] = (ss[i] == 'B');
        if (s[i] == 0) {
            cnt_0++;
        } else {
            cnt_1++;
        }
    }
    if (cnt_0 != a + c + d || cnt_1 != b + c + d) {
        cout << "NO\n";
        return;
    }
//    cout << "here\n";
    for (int i = 0; i < n - 1; i++) {
        if (s[i] != s[i + 1]) {
            int e = i + 1;
            while (e + 1 < n && s[e + 1] != s[e]) {
                e++;
            }
            len[s[i] * 2 + s[e]].pb(e - i + 1);
            i = e;
        }
    }
    for (int q = 0; q < 4; q++) {
        sort(all(len[q]));
    }
//    for (int q = 0; q < 4; q++) {
//        cerr << q << ": ";
//        for (int L : len[q]) {
//            cerr << L << " ";
//        }
//        cerr << "\n";
//    }
    update(1, c);
    update(2, d);
//    cerr << c << " " << d << "\n";

    update(0, c);
    update(3, c);
    update(3, d);
    update(0, d);
//    cerr << c << " " << d << "\n";

//    for (int q = 0; q < 4; q++) {
//        cerr << q << ": ";
//        for (int L : len[q]) {
//            cerr << L << " ";
//        }
//        cerr << "\n";
//    }

    for (int i = 0; i < len[2].size(); i++) {
        if (len[2][i] >= 2) {
            len[2][i] -= 2;
        }
    }
    for (int i = 0; i < len[1].size(); i++) {
        if (len[1][i] >= 2) {
            len[1][i] -= 2;
        }
    }
    update(2, c);
    update(1, d);
//    cerr << c << " " << d << "\n";
    if (!c && !d) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    for (int q = 0; q < 4; q++) {
        len[q] = {};
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}