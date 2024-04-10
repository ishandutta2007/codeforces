#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    int N = S.size();
    int la = -1;
    string T;
    vector<int> X;
    for (int i = 0; i < N; i++) {
        if (i == N - 1 || S[i] != S[i + 1]) {
            X.push_back(i - la);
            T.push_back(S[i]);
            la = i;
        }
    }
    string TT = T;
    reverse(TT.begin(), TT.end());
    bool ok = true;

    int C = X.size() / 2;
    if (T == TT) {
        if (X[C] <= 1) {
            ok = false;
        }
        for (int i = 0; i < C; i++) {
            if (X[i] + X[X.size() - 1 - i] < 3) {
                ok = false;
            }
        }
    } else {
        ok = false;
    }
    if (ok) {
        cout << X[C] + 1 << endl;
    } else {
        cout << 0 << endl;
    }
}