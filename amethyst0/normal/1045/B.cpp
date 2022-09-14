#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int> p_func(const vector<int>& s) {
    int n = sz(s);
    vector<int> p(n);
    for (int i = 1; i < n; ++i) {
        int j = p[i - 1];
        while (j && s[i] != s[j]) {
            j = p[j - 1];
        }
        if (s[i] == s[j]) {
            ++j;
        }
        p[i] = j;
    }
    return p;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b = a;
    vector<int> t;
    for (int i = 0; i < n; ++i) {
        int x = a[(i + 1) % n] - a[i];
        if (x <= 0) {
            x += m;
        }
        t.pb(x);
    }

    //cout << "!" << t[0] << " " << t[1] << endl;

    for (int i = 0; i < n; ++i) {
        a[i] = m - a[i];
        if (a[i] < 0) {
            a[i] += m;
        }
    }
    sort(all(a));
    vector<int> d;
    for (int i = 0; i < n; ++i) {
        int x = a[(i + 1) % n] - a[i];
        if (x <= 0) {
            x += m;
        }
        d.pb(x);
    }
    //cout << "!" << d[0] << " " << d[1] << endl;

    vector<int> vct = t;
    vct.pb(-1);
    for (int i = 0; i < sz(d); ++i) {
        vct.pb(d[i]);
    }
    for (int i = 0; i < sz(d) - 1; ++i) {
        vct.pb(d[i]);
    }

    vector<int> p = p_func(vct);
    vector<int> ans;
    for (int i = sz(t) + sz(d); i < sz(vct); ++i) {
        if (p[i] == sz(t)) {
            int j = i - sz(t) - sz(d);
            int val = b[0] - a[j];
            if (val < 0) {
                val += m;
            }
            ans.pb(val);
        }
    }

    sort(all(ans));
    cout << sz(ans) << "\n";
    if (!ans.empty()) {
        for (int x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    
}