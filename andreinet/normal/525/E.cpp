#include <bits/stdc++.h>
#define bitCount(x) __builtin_popcount(x)
using namespace std;

typedef long long i64;

const int Nmax = 30, MaxP = 1594323 + 4;

i64 Fact[20];
int A[Nmax];

i64 Sum1[MaxP], Sum2[MaxP];
int Cnt1[MaxP], Cnt2[MaxP];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int N, K;
    i64 S;
    cin >> N >> K >> S;

    for (int i = 1; i <= N; ++i)
        cin >> A[i];

    Fact[0] = 1;
    for (int i = 1; i <= 19; ++i)
        Fact[i] = Fact[i - 1] * i;

    int N1 = N / 2, N2 = N - N1;

    int Kr = pow(3, N1);
    for (int conf = 0; conf < Kr; ++conf) {
        i64 sc = 0;
        int rconf = conf;
        int cnt = 0;
        for (int i = 1; i <= N1; ++i) {
            int r = rconf % 3;
            rconf /= 3;

            if (r == 0) continue;
            if (r == 1) sc += A[i];
            else {
                ++cnt;
                if (A[i] >= 19) {
                    sc = -1;
                    break;
                } else sc += Fact[A[i]];
            }
        }
        Sum1[conf] = sc;
        Cnt1[conf] = cnt;
    }

    Kr = pow(3, N2);
    for (int conf = 0; conf < Kr; ++conf) {
        i64 sc = 0;
        int rconf = conf;
        int cnt = 0;
        for (int i = N1 + 1; i <= N; ++i) {
            int r = rconf % 3;
            rconf /= 3;

            if (r == 0) continue;
            if (r == 1) sc += A[i];
            else {
                cnt++;
                if (A[i] >= 19) {
                    sc = -1;
                    break;
                } else sc += Fact[A[i]];
            }
        }
        Sum2[conf] = sc;
        Cnt2[conf] = cnt;
    }

    i64 ans = 0;
    for (int k = 0; k <= K; ++k) {
        if (K - k > N2) continue;

        unordered_map<i64, i64> values;
        int maxv = pow(3, N1);
        for (int conf = 0; conf < maxv; ++conf) {
            i64 sc = Sum1[conf];
            int cnt = Cnt1[conf];

            if (sc == -1 || cnt > k) continue;
            
            values[sc]++;
        }
        maxv = pow(3, N2);
        for (int conf = 0; conf < maxv; ++conf) {
            i64 sc = Sum2[conf];
            int cnt = Cnt2[conf];
            if (sc == -1 || cnt != K - k) continue;
            if (values.find(S - sc) != values.end())
                ans += values[S - sc];
        }
    }

    cout << ans << '\n';
}