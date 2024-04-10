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

int n, m;

pii s_to_pii(string& s) {
    return {s[0] * 10 + s[1], s[3] * 10 + s[4]};
}

string pii_to_s(pii t) {
    string ans(5, ':');
    ans[1] = t.fs % 10;
    t.fs /= 10;
    ans[0] = t.fs;

    ans[4] = t.sc % 10;
    t.sc /= 10;
    ans[3] = t.sc;
    return ans;
}

char symmetrical_char(char c) {
    if (c == 0)
        return 0;
    else if (c == 1)
        return 1;
    else if (c == 2)
        return 5;
    else if (c == 5)
        return 2;
    else if (c == 8)
        return 8;
    else
        return '#';
}

string get_symmetrical(string& s) {
    string ans(5, ':');
    forn (i, 0, 5)
        if (i != 2)
            ans[5 - i - 1] = symmetrical_char(s[i]);
    return ans;
}

pii get_next(pii t) {
    t.sc++;
    if (t.sc == m) {
        t.sc = 0;
        t.fs++;
        if (t.fs == n) {
            t.fs = 0;
        }
    }
    return t;
}

void print(string& s) {
    forn (i, 0, 2)
        cerr << (char)(s[i] + '0');
    cerr << ":";
    forn (i, 3, 5)
        cerr << (char)(s[i] + '0');
}

bool is_correct(pii t) {
    return 0 <= t.fs && t.fs < n &&
           0 <= t.sc && t.sc < m;
}

void solve() {
    cin >> n >> m;
    string s;
    cin >> s;
    forn (i, 0, 2)
        s[i] -= '0';
    forn (i, 3, 5)
        s[i] -= '0';
    pii t = s_to_pii(s);
    while (true) {
        string sym_s = get_symmetrical(s);
        bool ok = true;
        for (char c : sym_s)
            if (c == '#')
                ok = false;
        if (ok && is_correct(s_to_pii(sym_s)))
            break;
        t = get_next(t);
        s = pii_to_s(t);
        // print(s);
        // cerr << "\n" << t.fs << " " << t.sc << "\n";
    }
    forn (i, 0, 2)
        cout << (char)(s[i] + '0');
    cout << ":";
    forn (i, 3, 5)
        cout << (char)(s[i] + '0');
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