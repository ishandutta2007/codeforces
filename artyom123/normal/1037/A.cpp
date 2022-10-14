#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define pb emplace_back()
const int INF = 1e9;

int main() {
    long long n;
    cin >> n;
    long long now = 0;
    int ans = 0;
    for (long long i = 1; now < n; i++) {
        if (now >= i) {
            continue;
        }
        ans++;
        now += i;
    }
    cout << ans;
    return 0;
}