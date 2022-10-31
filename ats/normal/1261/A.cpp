#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        string S;
        cin >> S;
        string T;
        for (int i = 0; i < K - 1; i++) {
            T.push_back('(');
            T.push_back(')');
        }
        for (int i = 0; i < (N / 2) - K + 1; i++) {
            T.push_back('(');
        }
        for (int i = 0; i < (N / 2) - K + 1; i++) {
            T.push_back(')');
        }
        vector<pair<int, int>> res;
        for (int i = 0; i < N; i++) {
            if (S[i] != T[i]) {
                for (int j = i + 1; j < N; j++) {
                    if (S[i] != S[j]) {
                        reverse(S.begin() + i, S.begin() + (j + 1));
                        res.emplace_back(i + 1, j + 1);
                        break;
                    }
                }
            }
        }
        //cerr << S << endl;

        cout << res.size() << endl;
        for (int i = 0; i < res.size(); i++) {
            cout << res[i].first << " " << res[i].second << endl;
        }
    }
}