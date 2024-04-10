#include <bits/stdc++.h>

using namespace std;

const int MX = 200;

long long l[MX], r[MX];

bool check(long long x, long long d, int i) {
    bool ok = true;
    for (int j = 0; j < i; j++)
        ok = ok && (x + d <= l[j] || x >= r[j]);

    return ok;
}

int main()
{
    int n;
    scanf("%d", &n);

    set<long long> R = {1};
    for (int i = 0; i < n; i++) {
        long long s, d;
        scanf("%lld %lld", &s, &d);

        if (check(s, d, i)) {
            l[i] = s;
        }
        else {
            for (long long x : R) {
                if (check(x, d, i)) {
                    l[i] = x;

                    break;
                }
            }
        }

        r[i] = l[i] + d;
        R.insert(r[i]);

        printf("%lld %lld\n", l[i], r[i] - 1);
    }

    return 0;
}