#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

#define long long long
#define mod 1000000007ll
#define M 100100
#define A 10

long bin(long x, long a) {
    long y = 1;
    while (a) {
        if (a & 1) {
            y = (y * x) % mod;
        }
        x = (x * x) % mod;
        a >>= 1;
    }
    return y;
}

int n;
string rule[M], s;
long len[M][A], d[M][A];

void read() {
    cin >> s;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> rule[i];
        for (auto & x : rule[i])
            x = x - '0';
    }
    for (auto & x : s) {
        x = x - '0';
        //cout << ((int) x) << "-\n";
    }
}

void calc(const string &x, int step, long &leng, long &rem) {
    leng = rem = 0;

    for (int i = (int) x.length() - 1; i >= 0; --i) {
        rem = (rem + d[step][(int)x[i]] * bin(10, leng)) % mod;
        leng += len[step][(int)x[i]];
        //cout << ((int) x[i]) << "!\n";
    }

    leng %= (mod - 1);
}

void din() {
    for (int i = 0; i < A; ++i) {
        len[n][i] = 1;
        d[n][i] = i;
    }

    for (int i = n - 1; i >= 0; --i)
        for (int j = 0; j < A; ++j)
            if (rule[i][0] == j) {
                calc(rule[i].substr(3, rule[i].length() - 3), i + 1, len[i][j], d[i][j]);
            }
            else {
                len[i][j] = len[i + 1][j];
                d[i][j] = d[i + 1][j];
            }

    long len, rem;
    calc(s, 0, len, rem);
    cout << rem << "\n";
}

int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    read();
    din();
    return 0;
}