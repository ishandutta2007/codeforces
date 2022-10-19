#include <bits/stdc++.h>


using namespace std;

const int M = 2000000;

int a[M], n;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int w;
        cin >> w;
        a[w]++;
    }

    for (int i = 0; i + 1 < M; ++i) {
        a[i + 1] += a[i] / 2;
        a[i] %= 2;
    }

    int ans = 0;
    for (int i = 0; i < M; ++i)
        if (a[i])
            ++ans;

    cout << ans << "\n";
    return 0;
}