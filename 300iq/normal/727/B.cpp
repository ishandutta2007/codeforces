#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for (int i = 0; i < (int) (n); i++)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define bit(x) __builtin_popcount(x)

pair <int, int> get(string s) {
    int t = (int) s.size();
    t--;
    t--;
    t--;
    int cop = 0;
    if (t >= 0 && s[t] == '.') {
        cop = (s[t + 1] - '0') * 10 + (s[t + 2] - '0');
        s.pop_back();
        s.pop_back();
    }
    int g = 0;
    for (auto c : s) {
        if (c != '.') g = g * 10 + (c - '0');
    }
    return {g, cop};
}

string to_stre(ll x) {
    if (x == 0) return "0";
    string s = "";
    while (x > 0) {
        s += (x % 10 + '0');
        x /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    #ifdef ONPC
        freopen("a.in", "r", stdin);
        freopen("a.out", "w", stdout);
    #else
        //
        //
    #endif
    string s;
    cin >> s;
    ll rubl = 0, cop = 0;
    for (int i = 0; i < (int) s.size(); ) {
        while (s[i] >= 'a' && s[i] <= 'z') {
            i++;
        }
        string f = "";
        while ((s[i] >= '0' && s[i] <= '9') || (s[i] == '.')) {
            f += s[i];
            i++;
        }
        auto v = get(f);
        rubl += v.fc, cop += v.sc;
    }
//    return 0;
    while (cop >= 100) {
        rubl++;
        cop -= 100;
    }
    string t = to_stre(rubl);
    s = "";
    reverse(all(t));
    for (int i = 0; i < (int) t.size(); i++) {
        s += t[i];
        if (i != (int) t.size() - 1 && i != 0 && i % 3 == 2) {
            s += ".";
        }
    }
    reverse(s.begin(), s.end());
    cout << s;
    if (cop != 0) {
        cout << '.';
        if (cop < 10) cout << '0';
        cout << cop;
    }
    cout << endl;
}