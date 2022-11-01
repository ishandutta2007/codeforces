#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    string A, B, C;
    cin >> A >> B >> C;

    A += B;
    sort(A.begin(), A.end());
    sort(C.begin(), C.end());

    cout << (A == C ? "YES\n": "NO\n");
}