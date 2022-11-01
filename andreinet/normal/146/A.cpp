#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int N;
    string S;
    cin >> N >> S;

    bool ok = true;
    int s1 = 0, s2 = 0;
    for (int i = 0; i < N; ++i) {
        if (S[i] != '4' && S[i] != '7') ok = false;
        (i < N / 2 ? s1: s2) += S[i] - '0';
    }
    if (s1 != s2) ok = false;

    cout << (ok ? "YES\n": "NO\n");
}