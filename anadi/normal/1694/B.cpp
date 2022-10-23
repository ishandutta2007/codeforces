#include <bits/stdc++.h>

using namespace std;

const int N = 200'007;

int n;
char in[N];

int main()
{
    int cases;
    scanf("%d", &cases);

    while (cases--) {
        scanf("%d", &n);
        scanf("%s", in + 1);

        long long ans = n;
        for (int i = 2; i <= n; ++i) {
            if (in[i] != in[i - 1]) {
                ans += i - 1;
            }
        }

        printf("%lld\n", ans);
    }

    return 0;
}