#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

typedef long long i64;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    ios::sync_with_stdio(false);

    int h; i64 n;
    cin >> h >> n;
    n--;

    i64 ans = 0;
    bool ok = false;
    for (int i = 0; i < h; ++i) {
        if (ok) n ^= 1LL << (h - i - 1);
        if ((n & (1LL << (h - i - 1))) != 0) {
            ans += (1LL << (h - i)) - 1;
        } else {
            ok ^= true;
        }
        ++ans;
    }

    cout << ans << '\n';
}