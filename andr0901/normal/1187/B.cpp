#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
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

void calc_pr(const string& s, vector <vector <int>>& pr) {
    pr.resize(sz(s) + 1, vector <int> (26));
    forn (i, 0, sz(s)) 
        forn (j, 0, 26) 
            pr[i + 1][j] = pr[i][j] + (s[i] - 'a' == j);
}

bool check(int x, const vector <vector <int>>& pr_s, const vector <int>& pr_t) {
    forn (i, 0, 26)
        if (pr_s[x + 1][i] < pr_t[i])
            return false;
    return true;
}

int bin_search(int l, int r, const vector <vector <int>>& pr_s, const vector <int>& pr_t) {
    if (r - l == 1)
        return r;
    int m = (l + r) / 2;
    if (check(m, pr_s, pr_t))
        return bin_search(l, m, pr_s, pr_t);
    else
        return bin_search(m, r, pr_s, pr_t);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    vector <vector <int>> pr_s;
    calc_pr(s, pr_s);
    int m;
    cin >> m;
    forn (i, 0, m) {
        string t;
        cin >> t;
        vector <vector <int>> pr_t;
        calc_pr(t, pr_t);
        cout << bin_search(-1, sz(s) - 1, pr_s, pr_t.back()) + 1 << "\n";
    }

    return 0;
}