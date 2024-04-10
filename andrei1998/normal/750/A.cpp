#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int mins = 240 - k;
    int cnt = 0;

    while (cnt + 1 <= n && mins - (cnt + 1) * 5 >= 0) {
        ++ cnt;
        mins -= 5 * cnt;
    }

    cout << cnt << '\n';
    return 0;
}