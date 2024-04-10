#include <bits/stdc++.h>

using namespace std;
#define left osodif
#define right lsdkafljdf

const int M = 103;

int n, a[M], t;
vector<int> as;
int d[M][M][M];
int s[M][M], left[M][M], right[M][M];

void read() {
    cin >> n >> t;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        as.push_back(a[i]);
    }
    sort(as.begin(), as.end());
    as.erase(unique(as.begin(), as.end()), as.end());
    for (int i = 1; i <= n; ++i) {
        a[i] = lower_bound(as.begin(), as.end(), a[i]) - as.begin();
    }
}



void din() {
    for (int k = 1; k <= n; ++k)
        for (int l = 0; l < n; ++l)
            for (int r = l; r < n; ++r) 
                if (l <= a[k] && a[k] <= r) {
                    d[l][r][k] = max(d[l][r][k - 1], d[l][a[k]][k - 1] + 1);
                } else {
                    d[l][r][k] = d[l][r][k - 1];
                }

    for (int l = 0; l < n; ++l)
        for (int r = l; r < n; ++r)
            s[l][r] = d[l][r][n];

    for (int k = 1; k < n; ++k)
        for (int v = 0; v < n; ++v) {
            for (int to = 0; to <= v; ++to) {
                left[v][k] = max(left[v][k], left[to][k - 1] + s[to][v]);
            }
            for (int to = v; to < n; ++to) {
                right[v][k] = max(right[v][k], right[to][k - 1] + s[v][to]);
            }
        }

    int ans = 0;
    for (int v = 0; v < n; ++v)
        for (int l = 0; l < n; ++l)
            for (int r = 0; r < n; ++r)
                if (l + r <= t) {
                    ans = max(ans, left[v][l] + (t - l - r) * s[v][v] + right[v][r]);
                }
    
    cout << ans << endl;
}

int main() {
    read();
    din();
    return 0;
}