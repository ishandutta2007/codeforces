#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 1'000'007;
const int C = 32;

const int MOD = 1'000'000'007;
const ll INF = 1LL * MOD * MOD;

int n;
string s;
int suf[N];

int opt[N][C + 1];
bool dp[N][C + 1];

void solve_dp()
{
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= C; ++j) {
            dp[i][j] = false;
        }
    }

    auto get_val = [&](int from, int to) {
        int ret = 0;
        for (int i = from; i < to; ++i) {
            ret = ret * 2 + s[i] - '0';
        }

        return ret;
    };

    dp[0][0] = true;
    for (int i = 0; i < n; ++i) {
        for (int sum = 0; sum <= C; ++sum) {
            if (!dp[i][sum]) {
                continue;
            }

            if (s[i] == '0') {
                dp[i + 1][sum] = true;
                opt[i + 1][sum] = i;
                continue;
            }

            for (int len = i + 1; len <= i + 5 && len <= n; ++len) {
                int t = get_val(i, len);
                if (sum + t > C) {
                    break;
                }

                dp[len][sum + t] = true;
                opt[len][sum + t] = i;
            }
        }
    }
    
    int cur = n, v = 0;
    for (int goal = 1; goal <= C; goal *= 2) {
        if (dp[n][goal]) {
            v = goal;
            break;
        }
    }

    assert(v);
    vector <pair <int, int> > ans;

    while (cur) {
        int pcur = opt[cur][v];
        v -= get_val(pcur, cur);
        ans.push_back({pcur + 1, cur});
        cur = pcur;
    }

    reverse(ans.begin(), ans.end());
    printf("%lu\n", ans.size());

    for (auto [l, r]: ans) {
        printf("%d %d\n", l, r);
    }
}

void solve()
{
    cin >> s;
    n = s.size();

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += s[i] - '0';
    }

    suf[n] = 0;
    for (int i = n - 1; i >= 0; --i) {
        suf[i] = suf[i + 1] + s[i] - '0';
    }

    if (sum == 0) {
        puts("-1");
        return;
    }

    int goal = 1;
    while (goal < sum) {
        goal *= 2;
    }

    if (goal <= C) {
        solve_dp();
        return;
    }

    vector <pair <int, int> > ans;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            ans.push_back({i, i});
            continue;
        }

        int cur = 1;
        int ptr = i + 1;

        while (ptr < n) {
            cur = cur * 2 + s[ptr] - '0';
            if (suf[ptr + 1] + cur > goal) {
                cur /= 2;
                ptr--;
                break;
            }

            ++ptr;
        }

        if (ptr == n) {
            ptr--;
        }

        goal -= cur;
        ans.push_back({i, ptr});
        i = ptr;
    }

    if (goal == 0) {
        printf("%lu\n", ans.size());
        for (auto [l, r]: ans) {
            printf("%d %d\n", l + 1, r + 1);
        }
    } else {
        exit(1);
        puts("-1");
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int cases = 1;
    cin >> cases;

    while (cases--) {
        solve();
    }

    return 0;
}