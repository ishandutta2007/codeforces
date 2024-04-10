#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

typedef long long i64;

const int Nmax = 305;

int A[Nmax];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    ios::sync_with_stdio(false);

    int N, T, R;
    cin >> N >> T >> R;

    if (T < R) {
        puts("-1");
        return 0;
    }

    for (int i = 1; i <= N; ++i)
        cin >> A[i];
    sort(A + 1, A + N + 1);

    int ans = 0;
    priority_queue<int> Q;
    for (int i = 1; i <= N; ++i) {
        while (!Q.empty() && -Q.top() + T <= A[i])
            Q.pop();
        int pos = A[i];
        while (int(Q.size()) < R) {
            Q.push(-pos);
            pos--;
            ++ans;
        }
    }

    cout << ans << '\n';
}