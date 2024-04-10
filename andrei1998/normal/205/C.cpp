#include <iostream>
#include <algorithm>

#define lint long long int
using namespace std;

lint solve(lint nr) {
    int v[30];
    int sz = 0;

    do {
        v[++ sz] = nr % 10;
        nr /= 10;
    } while (nr);

    reverse(v + 1, v + sz + 1);

    if (sz == 1)
        return v[1];

    lint ans = 9;

    lint interne = 1;
    for (int digits = 2; digits < sz; ++ digits) {
        ans += interne * 9;
        interne *= 10;
    }

    for (int i = 2; i < sz; ++ i) {
        nr *= 10;
        nr += v[i];
    }

    if (v[1] <= v[sz]) {
        ans += (min(v[1], v[sz]) - 1LL) * interne;
        ans += (nr + 1);
    }
    else {
        for (int c = 1; c < v[1]; ++ c)
            ans += interne;
        ans += nr;
    }

    return ans;
}

int main()
{
    lint l, r;
    cin >> l >> r;

    cout << solve(r) - solve(l - 1) << '\n';
    return 0;
}