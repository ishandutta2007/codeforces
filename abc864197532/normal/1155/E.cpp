#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << #x << ' ' << x << endl;
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int mod = 1e6 + 3, abc = 864197532, N = 100000, logN = 17, M = 11;

lli modpow(lli a, int b) {
    lli ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) ans = ans * a % mod;
    }
    return ans;
}

int ask(int x) {
    cout << "? " << x << endl;
    cin >> x;
    return x;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector <vector <long long>> mat(M, vector <long long>(M + 1, 0));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            mat[i][j] = modpow(i, j);
        }
        mat[i][M] = ask(i);
    }
    for (int i = 0; i < M; ++i) {
        long long times = modpow(mat[i][i], mod - 2);
        for (int k = 0; k < M + 1; ++k) {
            mat[i][k] = mat[i][k] * times % mod;
        }
        for (int j = 0; j < M; ++j) if (i ^ j) {
            times = mat[j][i];
            for (int k = 0; k < M + 1; ++k) {
                mat[j][k] -= mat[i][k] * times % mod;
                if (mat[j][k] < 0) mat[j][k] += mod;
            }
        }
    }
    for (int i = 0; i < mod; ++i) {
        lli al = 0;
        for (int j = 0; j < M; ++j) {
            al = (al + modpow(i, j) * mat[j][M]) % mod;
        }
        if (al == 0) {
            cout << "! " << i << endl;
            exit(0);
        }
    }
    cout << "! -1" << endl;
    exit(0);
}