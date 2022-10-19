#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

#define M 1000100

int s[2 * M];

bool is(int k, int x) {
    int l = k + x - 1, r = 2 * k - 1;
    while (l < M) {
        if (s[r] - s[l] > 0)
            return true;
        r += k;
        l += k;
    }
    return false;
}

int bin(int k) {
    int l = 0, r = k - 1, m;
    while (l < r) {
        m = (l + r) / 2 + 1;
        if (is(k, m))
            l = m;
        else
            r = m - 1;
    }
    return l;
}

int main() {

    ios_base::sync_with_stdio(false);

    int n;

    cin >> n;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        s[x]++;
    }

    for (int i = 1; i < 2 * M; ++i)
        s[i] += s[i - 1];

    int ans = 0;

    for (int i = 1; i < M; ++i)
        if (s[i] - s[i - 1] > 0)
            ans = max(ans, bin(i));

    cout << ans << "\n";

    return 0;
}