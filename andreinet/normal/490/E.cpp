#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

const int Nmax = 100005;

const int Pow10[] = {1, 1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8, 1e9};
int Values[Nmax];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    int N;
    scanf("%d\n", &N);

    int refval = 0, lastcnt = 0;
    for (int i = 0; i < N; ++i) {
        char nmb[12];
        scanf("%s", nmb);
        int K = strlen(nmb);
        reverse(nmb, nmb + K);
        if (K < lastcnt) {
            puts("NO");
            return 0;
        }

        assert(K <= 8);

        int curr = 0, cmr = 0;
        bool can = false;
        for (int j = 0; j < K; ++j) {
            if (nmb[j] == '?') {
                int mm = j == K - 1 ? 1: 0;
                int minval = mm;
                minval = max(minval, refval / Pow10[j] % 10);
                if (can == false && minval == refval / Pow10[j] % 10) ++minval;
                if (minval < 10) {
                    can = true;
                    if (minval > refval / Pow10[j] % 10) curr = cmr;
                    curr += Pow10[j] * minval;
                } else {
                    minval = mm;
                    curr = cmr;
                    curr += Pow10[j] * minval;
                    can = false;
                }
            } else {
                int dig1 = nmb[j] - '0', dig2 = refval / Pow10[j] % 10;
                if (dig1 < dig2) {
                    can = false;
                    curr = cmr;
                }
                if (dig1 > dig2) {
                    can = true;
                    curr = cmr;
                }
                curr += Pow10[j] * dig1;
                cmr += Pow10[j] * dig1;
            }
        }

        Values[i] = curr;
        if (curr <= refval) {
            puts("NO");
            return 0;
        }
        assert(curr < Pow10[K] && curr >= Pow10[K - 1]);
        for (int j = 0; j < K; ++j)
            assert(nmb[j] == '?' || curr / Pow10[j] % 10 == nmb[j] - '0');
        assert(curr > refval);

        lastcnt = K;
        refval = curr;
    }

    puts("YES");
    for (int i = 0; i < N; ++i) {
        printf("%d\n", Values[i]);
        assert(i == 0 || Values[i] > Values[i - 1]);
    }
}