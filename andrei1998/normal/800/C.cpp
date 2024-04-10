#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (!b)
        return a;
    int r = a % b;
    while (r) {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

void gcdExt(int a, int b, int &x, int &y) {
    if (b == 0)
        x = 1, y = 0;
    else {
        int x0, y0;
        gcdExt(b, a % b, x0, y0);

        x = y0;
        y = x0 - (a / b) * y0;
    }
}

int inv(int nr, int M) {
    int x, y;
    gcdExt(nr, M, x, y);
    x %= M;
    if (x < 0)
        x += M;
    return x;
}

int MOD;
int getMult(int A, int B) {
    int g = gcd(A, MOD);
    return (1LL * (B / g) * inv(A / g, MOD / g)) % MOD;
}

const int NMAX = 200000 + 5;
bool blocked[NMAX];

int dp[NMAX];
int nxt[NMAX];
vector <int> freq[NMAX];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N >> MOD;
    while (N --) {
        int val;
        cin >> val;
        blocked[val] = true;
    }

    for (int i = 0; i < MOD; ++ i)
        if (!blocked[i])
            freq[gcd(i, MOD)].push_back(i);

    for (int i = MOD; i; -- i)
        if (!freq[i].empty()) {
            dp[i] = freq[i].size();
            nxt[i] = -1;

            for (int j = 2 * i; j <= MOD; j += i)
                if (dp[j] + freq[i].size() > dp[i]) {
                    dp[i] = dp[j] + freq[i].size();
                    nxt[i] = j;
                }
        }

    vector <int> sol;

    int where = 1;
    int prod = 1;

    while (where != -1) {
        for (auto it: freq[where]) {
            sol.push_back(getMult(prod, it));
            prod = it;
        }

        where = nxt[where];
    }


    cout << sol.size() << '\n';
    for (int i = 0; i < sol.size(); ++ i)
        cout << sol[i] << " \n"[i + 1 == sol.size()];
    return 0;
}


/*#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cstring>

using namespace std;

int freq[100];
bool bad[100];

int main()
{
    int M;
    cin >> M;

    vector <int> v(M, 0);
    iota(v.begin(), v.end(), 0);

    bad[2] = 1;
    bad[5] = 1;

    do {
        memset(freq, 0, sizeof freq);
        int prod = 1;
        int i;
        for (i = 0; i < M - 2; ++ i) {
            prod = (prod * v[i]) % M;
            if (freq[prod] == 1 || bad[prod])
                break;
            else
                freq[prod] = 1;
        }

        if (i == M - 2) {
            cout << "YAY " << endl;
            for (int i = 0; i < M - 2; ++ i)
                cout << v[i] << ' ';
            cout << endl;
        }
    } while (next_permutation(v.begin(), v.end()));

    return 0;
}*/