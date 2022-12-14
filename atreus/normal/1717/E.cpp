#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

int phi[maxn];
vector<int> divs[maxn];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        phi[i] = i;
    for (int i = 1; i <= n; i++) {
        divs[i].push_back(i);
        for (int j = i + i; j <= n; j += i) {
            phi[j] -= phi[i];
            divs[j].push_back(i);
        }
    }
    phi[1] = 0;
    int answer = 0;
    for (int c = 1; c <= n - 2; c++)
        for (int d : divs[n - c])
            answer = (answer + 1LL * lcm(c, d) * phi[(n - c) / d]) % mod;
    cout << answer << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc = 1;
    while (tc--) {
        solve();
    }
}

/*
1, 5, 7, 11

2^2 * 3^1


*/