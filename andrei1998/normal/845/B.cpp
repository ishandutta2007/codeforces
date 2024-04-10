#include <bits/stdc++.h>

using namespace std;

vector <vector <int> > v;

int main()
{
    ios_base :: sync_with_stdio(false);

    for (int a1 = 0; a1 <= 9; ++ a1)
    for (int a2 = 0; a2 <= 9; ++ a2)
    for (int a3 = 0; a3 <= 9; ++ a3)
    for (int b1 = 0; b1 <= 9; ++ b1)
    for (int b2 = 0; b2 <= 9; ++ b2)
    for (int b3 = 0; b3 <= 9; ++ b3)
        if (a1 + a2 + a3 == b1 + b2 + b3)
            v.push_back({a1, a2, a3, b1, b2, b3});

    vector <int> rd(6);
    for (int i = 0; i < 6; ++ i) {
        char ch;
        cin >> ch;
        int digit = ch - '0';
        rd[i] = digit;
    }

    int ans = 6;
    for (auto it: v) {
        int cnt = 0;
        for (int i = 0; i < 6; ++ i)
            if (it[i] != rd[i])
                ++ cnt;
        if (cnt < ans)
            ans = cnt;
    }

    cout << ans << '\n';
    return 0;
}