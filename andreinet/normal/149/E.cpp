#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int Nmax = 100005, Kmax = 1005;

char A[Nmax], B[Kmax], C[Kmax];
int Pi[Kmax], Pir[Kmax];
int maxL[Nmax];

void getPi(int K, char B[], int Pi[]) {
    for (int i = 2, k = 0; i <= K; ++i) {
        while (k != 0 && B[i] != B[k + 1]) k = Pi[k];
        if (B[i] == B[k + 1]) k++;
        Pi[i] = k;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int N, M;
    cin >> (A + 1);
    N = strlen(A + 1);

    int ans = 0;

    cin >> M;
    while (M-- > 0) {
        cin >> (B + 1);
        int K = strlen(B + 1);

        memcpy(C, B, sizeof C);
        reverse(C + 1, C + K + 1);

        getPi(K, B, Pi);
        getPi(K, C, Pir);

        for (int i = 1, k = 0; i <= N; ++i) {
            while (k != 0 && A[i] != B[k + 1]) k = Pi[k];
            if (A[i] == B[k + 1]) k++;
            maxL[i] = max(maxL[i - 1], k);
        }

        bool ok = false;
        for (int i = N, k = 0; i >= 1; --i) {
            while (k != 0 && A[i] != C[k + 1]) k = Pir[k];
            if (A[i] == C[k + 1]) k++;
            if (maxL[i - 1] >= K - k && k > 0 && k < K) ok = true;
        }

        if (ok) ++ans;
    }
    cout << ans << '\n';
}