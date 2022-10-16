#include <iostream>

using namespace std;

const int NMAX = 1000 + 5;

bool lin[NMAX];
bool col[NMAX];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++ i)
        lin[i] = col[i] = true;

    int l, c;
    while (m --) {
        cin >> l >> c;
        lin[l] = false;
        col[c] = false;
    }

    int ans = 0;
    for (int i = 2; i <= (n + 1) / 2 - (n & 1); ++ i) {
        int val = lin[i] + col[i] + lin[n - i + 1] + col[n - i + 1];
        ans += val;
    }

    //Edge case for odd n
    if (n & 1)
        ans += (lin[(n + 1) / 2] | col[(n + 1) / 2]);

    cout << ans << '\n';
    return 0;
}