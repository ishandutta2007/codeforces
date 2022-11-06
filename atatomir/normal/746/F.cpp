#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 200011

const int dim = 10000;

struct aib {
    int whole = 0;
    int data[dim + 11];

    int zrs(int x) {
        return (x ^ (x - 1)) & x;
    }

    void add(int pos, int x) {
        whole += x;
        while (pos <= dim) {
            data[pos] += x;
            pos += zrs(pos);
        }
    }

    int sum(int x) {
        int ans = 0;
        while (x > 0) {
            ans += data[x];
            x -= zrs(x);
        }
        return x;
    }

    int cb(int x) {
        int ans = 0;

        for (int step = 1 << 14; step > 0; step >>= 1)
            if (ans + step <= dim)
                if (data[ans + step] <= x)
                    ans += step, x -= data[ans];

        return ans;
    }

    int first() {
        return cb(0) + 1;
    }

    int last() {
        return cb(whole - 1) + 1;
    }
};

int n, w, k, i, l, r;
int a[maxN], t[maxN];
aib full, half;

int sum_a, sum_t;
int ans;

void balance_add() {
    while (full.whole > 0 && half.whole > 0 && full.last() > half.first()) {
        int tm = half.first();
        int tm2 = full.last();

        full.add(tm, +1); sum_t += tm;
        half.add(tm, -1); sum_t -= (tm + 1) / 2;

        full.add(tm2, -1); sum_t -= tm2;
        half.add(tm2, +1); sum_t += (tm2 + 1) / 2;
    }
}

void balance() {
    while (full.whole > 0 && half.whole < w) {
        int tm = full.last();
        full.add(tm, -1); sum_t -= tm;
        half.add(tm, +1); sum_t += (tm + 1) / 2;
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d", &n, &w, &k);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (i = 1; i <= n; i++) scanf("%d", &t[i]);

    l = 1;
    for (r = 1; r <= n; r++) {
        sum_a += a[r];
        sum_t += t[r];

        full.add(t[r], +1);
        balance_add();
        balance();

        while (l <= r && sum_t > k) {
            int tm = t[l];

            if (tm <= full.last()) {
                full.add(tm, -1);
                sum_a -= a[l];
                sum_t -= t[l];
            } else {
                half.add(tm, -1);
                sum_a -= a[l];
                sum_t -= (t[l] + 1) / 2;
            }

            l++;
            balance();
        }

        ans = max(ans, sum_a);
    }

    printf("%d", ans);


    return 0;
}