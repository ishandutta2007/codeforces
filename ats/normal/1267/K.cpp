#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;
int solve(vector<int> T) {
    vector<int> TT = T;
    int res = 1;
    for (int i = 0; i < T.size() - 1; i++) {
        T[i + 1] += T[i];
        res *= (T[i + 1] - i);
    }
    for (int i = 0; i < TT.size(); i++) {
        for (int j = 1; j <= TT[i]; j++) {
            res /= j;
        }
    }
    return res;
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int N;
        int res = 1;
        cin >> N;
        vector<int> X;
        int a = 2;
        while (N > 0) {
            X.push_back(N % a);
            N /= a;
            a++;
        }
        vector<int> T(X.size() + 1, 0);
        for (int i = 0; i < X.size(); i++) {
            T[X[i]]++;
            // cerr << X[i] << endl;
        }
        res = solve(T);
        if(T[0] > 0 && T.back() == 0){
            T[0]--;
            T.pop_back();
            res -= solve(T);
        }
        cout << res - 1 << '\n';
    }
    return 0;
}