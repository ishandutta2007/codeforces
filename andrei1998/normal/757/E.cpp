#include <bits/stdc++.h>

using namespace std;

class InputReader {
public:
    InputReader() {
        input_file = stdin;
        cursor = 0;
        fread(buffer, SIZE, 1, input_file);
    }
    inline InputReader &operator >>(int &n) {
        while(buffer[cursor] < '0' || buffer[cursor] > '9') {
            advance();
        }
        n = 0;
        while('0' <= buffer[cursor] && buffer[cursor] <= '9') {
            n = n * 10 + buffer[cursor] - '0';
            advance();
        }
        return *this;
    }
private:
    FILE *input_file;
    static const int SIZE = 1 << 17;
    int cursor;
    char buffer[SIZE];
    inline void advance() {
        ++ cursor;
        if(cursor == SIZE) {
            cursor = 0;
            fread(buffer, SIZE, 1, input_file);
        }
    }
};

const int MOD = 1000000000 + 7;
const int INV2 = 500000000 + 4;

const int NMAX = 1e6 + 5;

vector <int> primes;
int low[NMAX];
int alias[NMAX];

void ciur() {
    for (int i = 2; i <= 1000000; ++ i) {
        if (!low[i]) {
            primes.push_back(i);
            low[i] = i;
        }
        for (int j = 0; j < primes.size() && primes[j] <= low[i] && primes[j] <= 1000000 / i; ++ j)
            low[i * primes[j]] = primes[j];
    }
}

void deco(vector <int> &v, int nr) {
    v.clear();
    while (nr > 1) {
        int lw = low[nr];
        int cnt = 0;
        while (low[nr] == lw) {
            nr /= low[nr];
            ++ cnt;
        }

        v.push_back(cnt);
    }
}

int dp[1000000 + 5][20];

int main()
{
    InputReader cin;

    ciur();
    dp[0][0] = 1;
    for (int i = 1; i < 20; ++ i)
        dp[0][i] = 2;

    for (int r = 1; r <= 1000000; ++ r) {
        for (int i = 0; i < 20; ++ i) {
            long long int ans = 0;
            for (int j = 0; j <= i; ++ j)
                ans += dp[r - 1][j] + dp[r - 1][i - j];

            ans %= MOD;
            dp[r][i] = (1LL * ans * INV2) % MOD;
        }
    }

    int q = 0;
    cin >> q;

    vector <int> v;
    while (q --) {
        int r, val;
        cin >> r >> val;

        deco(v, val);

        int ans = 1;
        for (auto it: v)
            ans = (1LL * ans * dp[r][it]) % MOD;

        cout << ans << '\n';
    }

    return 0;
}