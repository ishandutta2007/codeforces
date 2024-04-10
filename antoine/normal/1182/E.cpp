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
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % (mod - 1);
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


ll modPow(ll n, ll k) {
    k %= mod - 1;
    k += mod - 1;
    ll res = 1;
    for (n %= mod; k; k >>= 1) {
        if (k & 1)
            res = res * n % mod;
        n = n * n % mod;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    ll n, f[3], c;
    cin >> n >> f[0] >> f[1] >> f[2] >> c;

    ll ans = 1;

    {
        vector<vector<ll>> M = {{0, 0, 1},
                                {1, 0, 1},
                                {0, 1, 1}};
        M = matrixPow(M, n - 1);

        for (int rep = 0; rep < 3; ++rep) {
            vector<vector<ll>> u = {{rep == 0, rep == 1, rep == 2}};
            u = matrixMult(u, M);
            ans = ans * modPow(f[rep], u[0][0]) % mod;
        }
    }

    vector<vector<ll>> u = {{0, 0, 3, 0, 1}};

    vector<vector<ll>> M = {{0, 0, 0, 1,  0},
                            {1, 0, 0, 1,  0},
                            {0, 0, 1, 2,  0},
                            {0, 1, 0, 1,  0},
                            {0, 0, 1, -4, 1}};
    M = matrixPow(M, n - 1);
    u = matrixMult(u, M);

    ans = ans * modPow(c, u[0][0]) % mod;

    cout << (ans % mod + mod) % mod;
    return 0;
}