#include <bits/stdc++.h>

using namespace std;

#define long long long

const int M = 200200;

int n;
long a[M], b[M], pref[M], suff[M];
long k, x;

void read() {
    cin >> n >> k >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = a[i];
        for (int j = 0; j < k; ++j)
            b[i] *= x;
    }

    for (int i = 1; i <= n; ++i)
        pref[i] = pref[i - 1] | a[i];
    for (int i = n; i >= 1; --i)
        suff[i] = a[i] | suff[i + 1];
}

void kill() {
    long ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = max(ans, pref[i - 1] | b[i] | suff[i + 1]);
    cout << ans << endl;
}

int main() {
    read();
    kill();
    return 0;
}