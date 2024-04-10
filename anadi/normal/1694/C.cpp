#include <bits/stdc++.h>

using namespace std;

const int N = 200'007;

int n;
int in[N];
long long pref[N];

int main()
{
    int cases;
    scanf("%d", &cases);

    while (cases--) {
        bool nonzero = false;
        
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &in[i]);
            pref[i] = pref[i - 1] + in[i];
            nonzero |= in[i] != 0;
        }

        if (!nonzero) {
            puts("Yes");
            continue;
        }

        if (in[1] <= 0 || pref[n] != 0) {
            puts("No");
            continue;
        }

        bool ans = true, was_zero = false;
        for (int i = 1; i <= n; ++i) {
            if (pref[i] < 0) {
                ans = false;
                break;
            }

            if (pref[i] == 0) {
                was_zero = true;
            }

            if (was_zero && pref[i] > 0) {
                ans = false;
                break;
            }
        }

        puts(ans ? "Yes" : "No");
    }

    return 0;
}