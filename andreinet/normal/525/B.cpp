#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int Nmax = 200005;

char A[Nmax];
int Mars[Nmax];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int N;
    cin >> (A + 1);
    N = strlen(A + 1);

    int Q;
    cin >> Q;
    while (Q-- > 0) {
        int x;
        cin >> x;
        Mars[x]++;
        Mars[N - x + 2]--;
    }

    int s = 0;
    for (int i = 1; i <= N / 2; ++i) {
        s += Mars[i];
        if (s & 1) swap(A[i], A[N - i + 1]);
    }
    cout << (A + 1) << '\n';
}