#include <bits/stdc++.h>
 
int A[210000];
int P[210000];
int pre[210000];
 
int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int N, K;
        scanf("%d%d", &N, &K);
        for (int i = 0; i < N; ++i)
            scanf("%d", &A[i]);
        for (int i = 1; i < N - 1; ++i)
            P[i] = (A[i] > A[i - 1] && A[i] > A[i + 1]);
        for (int i = 1; i <= N; ++i) pre[i] = pre[i - 1] + P[i - 1];
        int maxi = 0;
        for (int i = 0; i + K - 1 < N; ++i)
            if (pre[maxi + K - 1] - pre[maxi + 1] < pre[i + K - 1] - pre[i + 1])
                maxi = i;
        printf("%d %d\n", pre[maxi + K - 1] - pre[maxi + 1] + 1, maxi + 1);
    }
}