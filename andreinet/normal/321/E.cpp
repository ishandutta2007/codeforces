#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

class Reader {
  public:
    Reader():
            m_stream(cin),
            m_pos(kBufferSize - 1),
            m_buffer(new char[kBufferSize]) {
        next();
    }
  
    Reader& operator>>(int& value) {
        value = 0;
        while (current() < '0' || current() > '9')
            next();
        while (current() >= '0' && current() <= '9') {
            value = value * 10 + current() - '0';
            next();
        }
        return *this;
    }
  
  private:
    const int kBufferSize = 32768;
  
    char current() {
        return m_buffer[m_pos];
    }
  
    void next() {
        if (!(++m_pos != kBufferSize)) {
            m_stream.read(m_buffer.get(), kBufferSize);
            m_pos = 0;
        }
    }
  
    istream& m_stream;
    int m_pos;
    unique_ptr<char[]> m_buffer;
};

const int NMAX = 4005, INF = 0x3f3f3f3f;

int cost[NMAX][NMAX];
int tcost[NMAX][NMAX];

int dp[NMAX], ndp[NMAX];

void solve(int left, int right, int l, int r) {
    if (left > right) return;
    int mid = (left + right) / 2;

    ndp[mid] = INF;
    int fpos = -1;
    for (int i = l; i < mid && i <= r; ++i) {
        int c = dp[i] + tcost[i + 1][mid];
        if (c < ndp[mid]) {
            ndp[mid] = c;
            fpos = i;
        }
    }

    solve(left, mid - 1, l, fpos);
    solve(mid + 1, right, fpos, r);
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    Reader cin;
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> cost[i][j];
        }
    }
    for (int i = n; i > 0; --i) {
        tcost[i][i] = 0;
        int sum = 0;
        for (int j = i + 1; j <= n; ++j) {
            sum += cost[i][j];
            tcost[i][j] = sum + tcost[i + 1][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        dp[i] = INF;
    }
    dp[0] = 0;

    for (int i = 1; i <= k; ++i) {
        solve(1, n, 0, n);
        memcpy(dp, ndp, sizeof dp);
    }

    cout << dp[n] << '\n';
}