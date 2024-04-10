#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    string A, B;
    cin >> A >> B;
    int N = A.length();

    int s1 = 0, s2 = 0, ans = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] == '7' && B[i] == '4') ++s1;
        else if (A[i] == '4' && B[i] == '7') ++s2;
    }
    ans = max(s1, s2);
    cout << ans << '\n';
}