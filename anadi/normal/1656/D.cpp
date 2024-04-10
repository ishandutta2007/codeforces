#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long n;
    scanf("%lld", &n);

    long long pw = 1;
    while (n % pw == 0) {
        pw *= 2LL;
    }

    if (2 * n / pw / (pw + 1)) {
        printf("%lld\n", pw);
        return;
    }

    pw /= 2;
    long long tmp = n / pw;

    if (tmp > 1 && 2 * n / tmp / (tmp + 1)) {
        printf("%lld\n", tmp);
        return;
    }

    puts("-1");
}

int main()
{
    int cases;
    scanf("%d", &cases);

    while (cases--) {
        solve();
    }

    return 0;
}