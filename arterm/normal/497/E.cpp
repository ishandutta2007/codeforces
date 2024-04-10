#include <bits/stdc++.h>

using namespace std;

#define long long long
#define mod 1000000007ll
#define M 35

int k = 34;
typedef vector<long> Line;

struct Matrix {
    long a[M][M];

    Matrix() {
        for (int i = 0; i <= k; ++i)
            fill(a[i], a[i] + (k + 1), 0);
    }

    Matrix operator * (const Matrix &to) const {
        Matrix ans;
        for (int i = 0; i <= k; ++i)
            for (int k1 = 0; k1 <= k; ++k1)
                for (int j = 0; j <= k; ++j)
                    ans.a[i][j] = (ans.a[i][j] + a[i][k1] * to.a[k1][j]) % mod;
        return ans;
    }
} one;

Line operator * (const Line &v, const Matrix &to) {
    Line ans(k + 1);
    for (int i = 0; i <= k; ++i)
        for (int j = 0; j <= k; ++j)
            ans[j] = (ans[j] + v[i] * to.a[i][j]) % mod;
    return ans;
}

Matrix initial(int t) {
    Matrix ans;
    for (int i = 0; i < k; ++i)
        if (i != t) {
            ans.a[i][i] = 1;
        } else {
            ans.a[i][k] = 1;
        }
    ans.a[k][k] = 2;
    ans.a[k][t] = -1;

    return ans;
}

long sum(long n) {
    long ans = 0;
    while (n) {
        ans += n % k;
        n /= k;
    }
    return ans % k;
}

void get(long n, vector<Matrix> A, Line &S) {
    if (n == 0)
        return;

    vector<Matrix> tA(k);
    vector<Matrix> suff(k + 1), pref(k + 1);
    pref[0] = one;
    for (int i = 0; i < k; ++i) {
        pref[i + 1] = pref[i] * A[i];
    }

    suff[k] = one;
    for (int i = k - 1; i >= 0; --i) {
        suff[i] = A[i] * suff[i + 1];
    }

    for (int i = 0; i < k; ++i) {
        tA[i] = suff[i] * pref[i];
    }

    long b = n / k;
    get(b, tA, S);

    for (int i = sum(b * k); i < sum(b * k) + n % k; ++i)
        S = S * A[i % k];
}

int main() {
    ios_base::sync_with_stdio(false);

    for (int i = 0; i < M; ++i)
        one.a[i][i] = 1;
    
    long n;
    cin >> n >> k;

    vector<Matrix> to;
    for (int i = 0; i < k; ++i)
        to.push_back(initial(i));

    Line b(k + 1);
    b[k] = 1;

    get(n, to, b);

    long ans = b[k];
    if (ans < 0)
        ans += mod;

    cout << ans << "\n";

    return 0;
}