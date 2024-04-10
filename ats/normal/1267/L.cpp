#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, L, K;
    cin >> N >> L >> K;
    string S;
    vector<string> res(N);
    cin >> S;
    sort(S.begin(), S.end());
    int l = 0;
    int r = S.size() - 1;
    int aa = 0;
    for (int t = 0; t < L; t++) {
        for (int i = 0; i < N; i++) {
            if (i < K && i >= aa) {
                res[i].push_back(S[l]);
                l++;
            } else {
                res[i].push_back(S[r]);
                r--;
            }
        }
        for (int i = aa; i < K - 1; i++) {
            if (res[i].back() != res[K - 1].back()) {
                aa = i + 1;
            }
        }
    }
    sort(res.begin(),res.end());
    for (int i = 0; i < N; i++) {
        cout << res[i] << endl;
    }
}