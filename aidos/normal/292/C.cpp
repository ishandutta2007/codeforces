#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
const int maxn = (int) 5e5 + 10;
const int mod = (int) 1e9 + 7;
int n;
set<int> s;
string val[330];
int good[330];

bool can(string &x, string &y) {
    int i = 0;
    int j = 0;
    while (i < x.size() && j < y.size()) {
        if (x[i] == '.') i++;
        if (y[y.size() - j - 1] == '.') j++;
        if (x[i] != y[y.size() - j - 1]) return false;
        i++;
        j++;
    }
    return true;
}

vector<string> ans;

void check(string x) {

    if (can(x, x)) {
        set<int> d;
        for(int i = 0; i  < x.size(); i++) {
            if(x[i] != '.')
                d.insert(x[i] - '0');
        }
        if(d.size() == s.size()) {
            ans.emplace_back(x);
        }
    }
}

void rec(int it, string ansL, string ansR) {
    if (!can(ansL, ansR)) return;
    if (it == 4) {
        check(ansL + "." + ansR);
        return;
    }
    for (int i = 0; i <= 255; i++) {
        if (good[i]) {
            string curL = ansL, curR = ansR;
            if (it % 2 == 0) {
                if (curL.size() > 0)
                    curL += ".";
                curL += val[i];
            } else {

                if (curR.size() > 0)
                    curR = "." + curR;
                curR = val[i] + curR;
            }

            rec(it + 1, curL, curR);

        }
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    for (int i = 0; i <= 255; i++) {
        val[i] = to_string(i);
        good[i] = 1;
        for (char c: val[i]) {
            if (s.count(c - '0') == 0) good[i] = 0;
        }
    }

    if(s.size() < 7) rec(0, "", "");
    cout << ans.size() << "\n";
    for (string &x:ans) cout << x << "\n";
}

int main() {
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}