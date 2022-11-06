#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 150011

struct frac {
    ll a, b;

    bool operator<(const frac& who)const {
        return a * who.b < b * who.a;
    }

    bool operator==(const frac& who)const {
        return a * who.b == b * who.a;
    }
};

struct task {
    ll p, t;
    frac ratio;
    double mini, maxi;

    bool operator<(const task &who)const {
        return ratio < who.ratio;
    }
};

int n, i;
task T[maxN];
double total_time;

bool cmp(const task& a, const task& b) {
    return a.p < b.p;
}

bool check(double c) {
    int i, j, k;
    double sum_time = 0.00;
    double inside_time;

    sort(T + 1, T + n + 1);
    reverse(T + 1, T + n + 1);

    for (i = 1; i <= n; i = j) {
        for (j = i; j <= n && T[i].ratio == T[j].ratio; j++);

        inside_time = 0.00;
        for (k = i; k < j; k++) inside_time += T[k].t;
        for (k = i; k < j; k++) {
            T[k].maxi = 1.00 * T[k].p * (1.00 - c * ((sum_time + T[k].t) / total_time));
            T[k].mini = 1.00 * T[k].p * (1.00 - c * ((sum_time + inside_time) / total_time));
        }

        sum_time += inside_time;
    }

    sort(T + 1, T + n + 1, cmp);

    double best = -1e18;
    j = 0;

    for (i = 1; i <= n; i++) {
        while (T[j + 1].p < T[i].p) {
            j++;
            best = max(best, T[j].maxi);
        }

        if (best > T[i].mini)
            return false;
    }

    return true;

}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%lld", &T[i].p), T[i].ratio.a = T[i].p;
    for (i = 1; i <= n; i++) scanf("%lld", &T[i].t), T[i].ratio.b = T[i].t, total_time += T[i].t;

    double l = 0.00;
    double r = 1.00;
    int steps = 30;

    while (steps-- > 0) {
        double mid = (l + r) / 2.00;

        if (check(mid))
            l = mid;
        else
            r = mid;
    }

    printf("%.9lf", (l + r) / 2.00);


    return 0;
}