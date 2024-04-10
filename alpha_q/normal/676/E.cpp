#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

long long bigMod (long long a, long long e, long long mod) {
    long long ret = 1;
    while (e) {
        if (e & 1) ret = (ret * a) % mod;
        a = (a * a) % mod;
        e >>= 1;
    }
    return ret;
}

long long toInt (string s) {
    bool flag = 0;
    if (s[0] == '-') s.erase(s.begin()), flag = 1;
    long long ret = 0;
    for (int j = 0; j < s.size(); j++) {
        ret *= 10;
        ret += (s[j] - '0');
    }
    if (flag) ret = -ret;
    return ret;
}

int n;
long long k;
string s;
int unknown = 0;
long long coeff[N];
long long value[20];
long long mod[] = {0, 101449, 29209, 1000000007, 1000000009, 96661, 49979693, 32452867};
long long Pow[20];

int main (int argc, char const *argv[]) {
    //freopen("input.txt", "r", stdin);

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> k;
    int pos = 0;
    bool constant = 1;
    for (int i = 0; i <= n; i++) {
        cin >> s;
        if (s[0] == '?') {
            ++unknown;
            if (i == 0) constant = 0;
        }
        else coeff[pos++] = toInt(s);
    }

    if (k == 0) {
        if (unknown == n + 1) cout << "No\n";
        else if (constant) cout << (coeff[0] == 0 ? "Yes\n" : "No\n");
        else cout << (pos & 1 ? "Yes\n" : "No\n");
    } else if (unknown) {
        if (n & 1) cout << "Yes\n";
        else cout << "No\n";
    } else {
        for (int i = 1; i <= 7; i++) value[i] = 0, Pow[i] = 1;
        for (int i = 0; i < pos; i++) {
            for (int j = 1; j <= 7; j++) {
                value[j] += coeff[i] * Pow[j], value[j] %= mod[j];
                Pow[j] *= k, Pow[j] %= mod[j];
            }
        }
        for (int i = 1; i <= 7; i++)
            if (value[i] != 0) {
                cout << "No\n";
                return 0;
            }
        cout << "Yes\n";
    }
    return 0;
}