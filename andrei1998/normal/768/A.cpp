#include <bits/stdc++.h>

using namespace std;

const int NMAX = 100000 + 5;

int v[NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; ++ i)
        cin >> v[i];
    sort(v + 1, v + N + 1);

    int l = 1;
    while (l + 1 <= N && v[l] == v[l + 1])
        ++ l;
    ++ l;

    int r = N;
    while (r - 1 >= 1 && v[r] == v[r - 1])
        -- r;
    -- r;

    if (l <= r)
        cout << r - l + 1 << '\n';
    else
        cout << "0\n";
    return 0;
}