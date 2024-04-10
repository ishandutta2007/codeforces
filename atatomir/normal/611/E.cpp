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

int n, i, a, b, c, x;
multiset<int> S;
int ans, best;
int how_X, how_Y;
int X, Y;

void try_solve(int lim_low, int lim_high, int lim) {
    while (true) {
        //! erase low < x < high
        auto it = S.upper_bound(lim_high);
        if (it == S.begin())
            return;

        it--;
        if (*it <= lim_low)
            return;

        S.erase(it);
        ans++;

        //! erase x <= lim
        /**/ it = S.upper_bound(lim);
        if (it == S.begin()) continue;

        it--;
        S.erase(it);
    }
}

void get_count() {
    X = a + b;
    Y = c;
    if (X > Y)
        swap(X, Y);

    for (auto e : S) {
        if (e <= X)
            how_X++;
        else
            how_Y++;
    }
}

int how_now() {
    if (how_Y >= how_X)
        return how_Y;
    return (how_X - how_Y + 1) / 2 + how_Y;
}

void give_answer() {
    printf("%d", best);
    exit(0);
}

void debug() {
    return;
    for (auto e : S)
        printf("%d ", e);
    printf("\n");
}

void get_out(int x) {
    if (x <= X)
        how_X--;
    else
        how_Y--;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d%d", &n, &a, &b, &c);

    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);

    for (i = 1; i <= n; i++) {
        scanf("%d", &x);
        if (x > a + b + c) {
            printf("-1");
            return 0;
        }

        S.insert(x);
    }


        debug();
    try_solve(b + c, a + b + c, 0);
        debug();
    try_solve(a + c, b + c, a);
        debug();
    try_solve( max(a + b, c) , a + c, b);
        debug();

    get_count();
    best = how_now() + ans;

    while (true) {
        auto it = S.upper_bound(c);
        if (it != S.begin()) {
            it--;
            get_out(*it);
            S.erase(it);
        } else
            give_answer();

        /**/ it = S.upper_bound(b);
        if (it != S.begin()) {
            it--;
            get_out(*it);
            S.erase(it);
        }

        /**/ it = S.upper_bound(a);
        if (it != S.begin()) {
            it--;
            get_out(*it);
            S.erase(it);
        }

        debug();

        ans++;
        best = min(best, ans + how_now());
    }

    give_answer();

    return 0;
}