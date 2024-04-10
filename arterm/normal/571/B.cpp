#include <bits/stdc++.h>

using namespace std;

const int M = 300300;
const int N = 5050;

#define long long long

const long INF = 1000000000000000ll;

int n, k;
long a[M];
long d[N][N];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a, a + n);


    int t = (n - 1) / k + 1;


    int s = k * t - n;

    assert(s * (t - 1) + (k - s) * t == n);


    for (int i = 0; i < N; ++i)
        fill(d[i], d[i] + N, INF);

    d[0][0] = 0;

    for (int i = 0; i <= s; ++i)
        for (int j = 0; j <= k - s; ++j) {
            int pos = i * (t - 1) + j * t;
            if (i >= 1)
                d[i][j] = min(d[i][j], d[i - 1][j] + a[pos - 1] - a[pos - (t - 1)]);
            if (j >= 1)
                d[i][j] = min(d[i][j], d[i][j - 1] + a[pos - 1] - a[pos - t]);
        }

    cout << d[s][k - s] << endl;

    return 0;
}