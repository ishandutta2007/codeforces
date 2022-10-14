#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()

const int INF = 1e9 + 1;

int main() {
    long long n, k;
    cin >> n >> k;
    cout << (k + n - 1) / n;
    return 0;
}