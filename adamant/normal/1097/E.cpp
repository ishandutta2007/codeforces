#include <bits/stdc++.h>
 
using namespace std;

#define all(x) begin(x), end(x)

const int maxn = 1e5 + 42;

int CNT = 0;

vector<int> find_inc(vector<int> p, int t) {
    int n = p.size();
    int d[n + 1], pos[n + 1], pr[n + 1];
    fill(d, d + n + 1, t == 0 ? maxn : 0);
    d[0] = t == 0 ? 0 : maxn;
    pr[0] = -1;
    pos[0] = -1;
    int mx = 0, ca = 0;
    for(int i = 0; i < n; i++) {
        CNT++;
        int j;
        if(t == 0) {
            j = upper_bound(d, d + n + 1, p[i], less<int>()) - d;
        } else {
            j = upper_bound(d, d + n + 1, p[i], greater<int>()) - d;
        }
        d[j] = p[i];
        pos[j] = i + 1;
        pr[i + 1] = pos[j - 1];
        if(j > ca) {
            ca = j;
            mx = i + 1;
        }
    }
    vector<int> ans;
    while(mx != -1) {
        ans.push_back(mx);
        mx = pr[mx];
    }
    reverse(all(ans));
    return ans;
}

vector<vector<int>> max_inc(vector<int> p, int t) {
    int n = p.size();
    int d[n + 1];
    fill(d, d + n + 1, t == 0 ? maxn : 0);
    d[0] = t == 0 ? 0 : maxn;
    int MX[n + 1];
    int mx = 0, ca = 0;
    for(int i = 0; i < n; i++) {
        int j;
        if(t == 0) {
            j = upper_bound(d, d + n + 1, p[i], less<int>()) - d;
        } else {
            j = upper_bound(d, d + n + 1, p[i], greater<int>()) - d;
        }
        d[j] = p[i];
        MX[i + 1] = j;
        if(j > ca) {
            ca = j;
            mx = i + 1;
        }
    }
    vector<vector<int>> ans(ca);
    for(int i = 0; i < n; i++) {
        ans[MX[i + 1] - 1].push_back(i + 1);
    }
    return ans;
}

vector<vector<int>> solve(vector<int> p) {
    auto A = find_inc(p, 0);
    auto B = find_inc(p, 1);
    if(B.size() > A.size()) {
        swap(A, B);
    }
    if(A.size() == p.size()) {
        return {A};
    } else {
        int j = 0;
        vector<int> np;
        vector<int> inv;
        for(int i = 0; i < p.size(); i++) {
            if(j < A.size() && A[j] - 1 == i) {
                j++;
            } else {
                np.push_back(p[i]);
                inv.push_back(i + 1);
            }
        }
        auto res = solve(np);
        for(auto &it: res) {
            for(auto &jt: it) {
                jt = inv[jt - 1];
            }
        }
        res.push_back(A);
        if(res.size() >= B.size()) {
            auto AA = max_inc(p, 0);
            auto BB = max_inc(p, 1);
            if(BB.size() < AA.size()) {
                swap(AA, BB);
            }
            return AA;
        }
        return res;
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    stringstream ss;
    while(t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for(int i = 0; i < n; i++) {
            cin >> p[i];
        }
        auto ans = solve(p);
        ss << ans.size() << endl;
        for(auto it: ans) {
            ss << it.size() << ' ';
            for(auto jt: it) {
                ss << p[jt - 1] << ' ';
            }
            ss << endl;
        }
    }
    cerr << CNT << endl;
    cout << ss.str() << endl;
    return 0;
}