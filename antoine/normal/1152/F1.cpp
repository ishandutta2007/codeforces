#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int mod = (int) 1e9 + 7;


vector<vector<ll>> matrixMult(const vector<vector<ll>> A, const vector<vector<ll>> B) {
    assert(!A.empty() && A[0].size() == B.size());
    vector<vector<ll>> C(A.size(), vector<ll>(B[0].size(), 0));
    for (int i = 0; i < (int) C.size(); ++i)
        for (int j = 0; j < (int) C[0].size(); ++j)
            for (int k = 0; k < (int) A[0].size(); ++k)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
    return C;
}

vector<vector<ll>> matrixIdentity(const int n) {
    vector<vector<ll>> M(n, vector<ll>(n, 0));
    for (int i = 0; i < n; ++i)
        M[i][i] = 1;
    return M;
}

vector<vector<ll>> matrixPow(vector<vector<ll>> A, ll k) {
    auto B = matrixIdentity(A.size());
    for (; k; k >>= 1) {
        if (k & 1)
            B = matrixMult(A, B);
        A = matrixMult(A, A);
    }
    return B;
}

int popCnt[1 << 5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    for (int x = 1; x < sizeof popCnt / sizeof popCnt[0]; ++x)
        popCnt[x] = 1 + popCnt[x & (x - 1)];

    int N, K, M;
    cin >> N >> K >> M;

    const int len = (K + 1) * (1 << M);
    vector<vector<ll>> u(1, vector<ll>(len, 0));
    u[0][0] = 1;

    const auto f = [&M](const int k, const int msk) {
        return k * (1 << M) + (msk & ((1 << M) - 1));
    };


    vector<vector<ll>> A(len, vector<ll>(len, 0));
    for (int k = 0; k <= K; ++k)
        for (int msk = 0; msk < (1 << M); ++msk) {
            A[f(k, msk)][f(k, msk << 1)]++;
            if (k < K)
                A[f(k, msk)][f(k + 1, msk << 1 | 1)] += popCnt[msk] + 1;
        }


    A = matrixPow(A, N);
    u = matrixMult(u, A);


    ll ans = accumulate(u[0].begin() + K * (1 << M), u[0].end(), 0LL);
    cout << ((ans % mod) + mod) % mod;
    return 0;
}