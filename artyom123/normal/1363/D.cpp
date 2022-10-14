#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back

const int INF = 1e9 + 1;

vector<vector<int>> s;
int mx_in = 0;

int get_ind_mx(vector<int> ind) {
    int sz = ind.size();
    if (sz == 1) {
        return ind[0];
    }
    vector<int> left;
    for (int i = 0; i < (int)ind.size() / 2; i++) left.pb(ind[i]);
    vector<int> right;
    for (int i = ind.size() / 2; i < (int)ind.size(); i++) right.pb(ind[i]);
    vector<int> q;
    for (auto &c : left) {
        for (auto &l : s[c]) q.pb(l);
    }
    cout << '?' << " " << q.size() << " ";
    for (auto &c : q) cout << c << " ";
    cout << endl;
    int ans;
    cin >> ans;
    if (ans == mx_in) return get_ind_mx(left);
    else return get_ind_mx(right);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        s.clear();
        s.resize(k);
        vector<int> usd(n + 1);
        for (int i = 0; i < k; i++) {
            int c;
            cin >> c;
            s[i].resize(c);
            for (auto &l : s[i]) cin >> l;
            for (auto &l : s[i]) usd[l] = 1;
        }
        vector<int> fq;
        for (int i = 1; i <= n; i++) if (usd[i]) fq.pb(i);
        cout << '?' << " " << fq.size() << " ";
        for (auto &c : fq) cout << c << " ";
        cout << endl;
        cin >> mx_in;
        vector<int> ind;
        for (int i = 0; i < k; i++) ind.pb(i);
        int ind_mx = get_ind_mx(ind);
        usd.assign(n + 1, 0);
        for (auto &c : s[ind_mx]) usd[c] = 1;
        vector<int> sq;
        for (int i = 1; i <= n; i++) if (!usd[i]) sq.pb(i);
        cout << '?' << " " << sq.size() << " ";
        for (auto &c : sq) cout << c << " ";
        cout << endl;
        int mx_out;
        cin >> mx_out;
        vector<int> ans(k);
        for (int i = 0; i < k; i++) {
            if (i == ind_mx) ans[i] = mx_out;
            else ans[i] = max(mx_out, mx_in);
        }
        cout << '!' << " ";
        for (auto &c : ans) cout << c << " ";
        cout << endl;
        string s;
        cin >> s;
    }
    return 0;
}