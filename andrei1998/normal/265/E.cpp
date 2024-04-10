#include <iostream>
#include <set>
#include <utility>
#include <cstring>
#include <cstdio>

#define lint long long int
using namespace std;

class InputReader {
    public:
        InputReader() {
            cursor = 0;
            fread(buffer, SIZE, 1, stdin);
        }
        inline InputReader &operator >>(int &n) {
            while((buffer[cursor] < '0' || buffer[cursor] > '9') && buffer[cursor] != '-') {
                advance();
            }
            n = 0;
            int semn = 1;
            if (buffer[cursor] == '-') {
                semn = -1;
                advance();
            }

            while('0' <= buffer[cursor] && buffer[cursor] <= '9') {
                n = n * 10 + buffer[cursor] - '0';
                advance();
            }

            n *= semn;
            return *this;
        }
    private:
        static const int SIZE = 1 << 17;
        int cursor;
        char buffer[SIZE];
        inline void advance() {
            ++ cursor;
            if(cursor == SIZE) {
                cursor = 0;
                fread(buffer, SIZE, 1, stdin);
            }
        }
};

const int NMAX = 100005;

int n;
int v[NMAX];
int c[NMAX];

lint dp[NMAX];
lint best[NMAX]; //best[color]

pair <lint, int> upp;
pair <lint, int> upp2;

lint best_other(int col) {
    if (upp.second == col)
        return upp2.first;
    else
        return upp.first;
}

const lint INF = (1LL << 60);

lint compute_dp(int a, int b) {
    upp = make_pair(0, 0);
    upp2 = make_pair(-INF, 1);

    for (int i = 1; i <= n; ++ i)
        best[i] = -INF;

    lint ans = 0;
    for (int i = 1; i <= n; ++ i) {
        //Egal
        dp[i] = 1LL * v[i] * a + best[c[i]];

        //Diferit
        dp[i] = max(dp[i], 1LL * v[i] * b + best_other(c[i]));

        if (dp[i] > ans)
            ans = dp[i];

        //Update
        if (dp[i] > best[c[i]]) {
            best[c[i]] = dp[i];

            if (dp[i] > upp.first) {
                if (c[i] != upp.second)
                    upp2 = upp;
                upp = make_pair(dp[i], c[i]);
            }
            else if (dp[i] > upp2.first)
                upp2 = make_pair(dp[i], c[i]);
        }
    }

    return ans;
}

int main()
{
    //ios_base :: sync_with_stdio(false);

    InputReader cin;

    int q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++ i)
        cin >> v[i];
    for (int i = 1; i <= n; ++ i)
        cin >> c[i];

    int a, b;
    while (q --) {
        cin >> a >> b;
        cout << compute_dp(a, b) << '\n';
    }

    return 0;
}