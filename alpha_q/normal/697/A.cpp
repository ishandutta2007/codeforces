#include <bits/stdc++.h>

using namespace std;

int main (int argc, char const *argv[]) {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    long long t, s, x;
    cin >> t >> s >> x;

    if (x >= t and (x - t) % s == 0) {
        printf("YES\n");
        return 0;
    }

    if (x > t + 1 and (x - t - 1) % s == 0) {
        printf("YES\n");
        return 0;
    }

    printf("NO\n");
    return 0;
}