#include <bits/stdc++.h>

using namespace std;

int main (int argc, char const *argv[]) {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    int n, M = 0, C = 0, m, c;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> m >> c;
        if (m > c) ++M;
        else if (c > m) ++C;
    }

    if (M > C) printf("Mishka\n");
    else if (M < C) printf("Chris\n");
    else printf("Friendship is magic!^^\n");
    return 0;
}