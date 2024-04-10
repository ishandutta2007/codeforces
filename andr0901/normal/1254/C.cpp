#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
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
#define int long long

int get_sgn(int i, int j, int k) {
    assert((i != j) && (j != k) && (i != k));
    cout << 2 << " " << i + 1 << " " << j + 1 << " " << k + 1 << endl;
    int ans;
    cin >> ans;
    return ans;
}

int get_s(int i, int j, int k) {
    assert((i != j) && (j != k) && (i != k));
    cout << 1 << " " << i + 1 << " " << j + 1 << " " << k + 1 << endl;
    int ans;
    cin >> ans;
    return ans;
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <int> sgn(n), s(n);
    vector <pii> left, right;
    forn (i, 2, n) {
        sgn[i] = get_sgn(0, 1, i);
        s[i] = get_s(0, 1, i);
        if (sgn[i] == 1)
            left.eb(s[i], i);
        else
            right.eb(s[i], i);
    }
    sort(rall(left)), sort(rall(right));
    vector <pii> r_l, r_r, l_l, l_r;
    if (!right.empty()) {
        forn (i, 1, sz(right)) {
            if (get_sgn(right[0].sc, 0, right[i].sc) == -1)
                r_r.eb(right[i]);
            else
                r_l.eb(right[i]);
        }
        sort(all(r_l)), sort(rall(r_r));
    }
    if (!left.empty()) {
        forn (i, 1, sz(left)) {
            if (get_sgn(left[0].sc, 0, left[i].sc) == -1)
                l_r.eb(left[i]);
            else
                l_l.eb(left[i]);
        }
        sort(all(l_l)), sort(rall(l_r));
    }
    cout << "0 1 ";
    for (auto i : r_l)
        cout << i.sc + 1 << " ";
    if (!right.empty())
        cout << right[0].sc + 1 << " ";
    for (auto i : r_r)
        cout << i.sc + 1 << " ";
    cout << "2 ";
    for (auto i : l_l)
        cout << i.sc + 1 << " ";
    if (!left.empty())
        cout << left[0].sc + 1 << " ";
    for (auto i : l_r)
        cout << i.sc + 1 << " ";
    cout << endl;
    return 0;
}