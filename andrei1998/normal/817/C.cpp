#include <bits/stdc++.h>

using namespace std;

typedef long long int lint;

lint getVal(lint nr) {
    lint sum  = 0;
    lint _nr = nr;
    while (nr) {
        sum += nr % 10;
        nr /= 10;
    }
    return _nr - sum;
}

int main()
{
    lint N, S;
    cin >> N >> S;

    lint ans = 0;
    for (lint i = max(1LL, S - 200); i <= min(N, S + 200); ++ i)
        ans += (getVal(i) >= S);
    ans += N - min(N, S + 200);

    cout << ans << '\n';
    return 0;
}