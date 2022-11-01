#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int Nmax = 105;
int A[Nmax];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int K;
    cin >> K;
    for (int i = 0; i < 12; ++i)
        cin >> A[i];
    sort(A, A + 12, greater<int>());

    int s = 0, cnt = 0;
    for (int i = 0; i < 12 && s < K; ++i) {
        s += A[i];
        ++cnt;
    }
    if (s >= K) cout << cnt << '\n';
    else cout << "-1\n";
}