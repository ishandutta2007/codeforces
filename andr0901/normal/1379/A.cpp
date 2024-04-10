//#pragma GCC optimize("Ofast")
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

#ifdef DEBUG
#else
    #define cerr if (false) cerr
#endif

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

const string t = "abacaba";

void solve() {
    int n;
    string s;
    cin >> n >> s;
    auto check = [&](string a) {
        int cnt = 0;
        forn (i, 0, sz(a)) {
            bool ok = true;
            if (i + sz(t) > n)
                continue;
            forn (j, 0, sz(t))
                if (a[i + j] != t[j])
                    ok = false;
            if (ok)
                ++cnt;
        }
        return cnt == 1;
    };
    forn (i, 0, n) {
        if (i + sz(t) > n)
            continue;
        bool ok = true;
        string a = s;
        forn (j, 0, sz(t)) {
            if (a[i + j] == '?')
                a[i + j] = t[j];
            else {
                if (a[i + j] != t[j])
                    ok = false;
            }
        }
        for (char& c : a)
            if (c == '?')
                c = 'z';
        if (ok && check(a)) {
            cout << "Yes\n" << a << "\n";
            return;
        } 
    }
    cout << "No\n";
    /*int cnt_restricted = 0, cnt_possible = 0;
    vector <bool> restricted(n, true), possible(n, true);
    forn (i, 0, n) {
        if (i + sz(t) > n) {
            restricted[i] = possible[i] = false;
            continue;
        }
        forn (j, i, i + sz(t))
            if (s[j] != t[j - i])
                restricted[i] = false;
        bool question_marks = false;
        forn (j, i, i + sz(t)) {
            if (s[j] != '?' && s[j] != t[j - i])
                possible[i] = false;
            if (s[j] == '?')
                question_marks = true;
        }
        //cerr << restricted[i] << " " << possible[i] << "\n";
        if (!question_marks)
            possible[i] = false;
        if (question_marks)
            restricted[i] = false;
        cnt_restricted += restricted[i];
        cnt_possible += possible[i];
    }
    //cerr << cnt_restricted << " " << cnt_possible << "\n";
    if (cnt_restricted > 1) {
        cout << "No\n";
        return;
    }
    if (cnt_restricted == 1) {
        cout << "Yes\n";
        for (char c : s) {
            if (c == '?')
                cout << 'z';
            else
                cout << c;
        }
        cout << "\n";
        return;
    }
    if (cnt_possible == 0) {
        cout << "No\n";
    } else {
        int idx = -1;
        forn (i, 0, n)
            if (possible[i]) {
                forn (j, 0, sz(t))
                    s[j + idx] = t[j];
            }
        if (idx == -1) {
            cout << "No\n";
            return;
        }
        //cerr << idx << "\n";
        forn (i, 0, sz(t))
            s[i + idx] = t[i];
        cout << "Yes\n";
        for (char c : s) {
            if (c == '?')
                cout << 'z';
            else
                cout << c;
        }
        cout << "\n";
        return;
    }*/
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}