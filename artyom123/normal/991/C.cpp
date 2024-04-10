#include <bits/stdc++.h>

using namespace std;

long long n;

bool good(long long m) {
    long long now = n;
    long long ans = 0;
    while (now > 0) {
        ans += min(m, now);
        now -= min(m, now);
        now -= now / 10;
    }
    return ans * 2 >= n;
}

int main() {
    cin >> n;
    long long l = 0, r = n;
    while (r - l > 1) {
        long long m = (l + r) / 2;
        if (good(m)) {
            r = m;
        }
        else {
            l = m;
        }
    }
    cout << r;
    return 0;
}