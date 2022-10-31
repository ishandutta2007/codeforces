#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    int res = 0;
    int mx = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        mx = max(A[i], mx);
    }
    vector<pair<int, int> > vp;
    int m = -1;
    int mxi = N - 1;
    vector<int> t;
    for (int i = 0; i < N; i++) {
        if (i > 0) {
            if (A[i] < m) {
                t.push_back(A[i]);
            } else {
                t.push_back(m);
            }
        }
        if (A[i] == mx) {
            mxi = i;
            break;
        }

        m = max(m, A[i]);
        vp.emplace_back(m, A[i + 1]);
    }
    vector<int> t2;
    for (int i = mxi + 1; i < N; i++) {
        t2.push_back(A[i]);
    }
    for (int i = 0; i < t.size(); i++) {
        t2.push_back(t[i]);
    }
    // for (int i = 0; i < t2.size(); i++) {
    //     cerr << t2[i] << " ";
    // }
    // cerr << endl;
    for (int i = 0; i < Q; i++) {
        int a;
        cin >> a;
        if (a <= vp.size()) {
            cout << vp[a - 1].first << " " << vp[a - 1].second << "\n";
        } else {
            cout << mx << " " << t2[(a - (int)vp.size() - 1) % (N - 1)] << "\n";
        }
    }
    return 0;
}