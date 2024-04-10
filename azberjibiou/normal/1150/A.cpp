#include <bits/stdc++.h>
using namespace std;
int A[200], B[200], N, M, K, ans;
int main()
{
    scanf("%d %d %d", &N, &M, &K);
    for(int i=0;i<N;i++)
    {
        scanf("%d", &A[i]);
    }
    for(int i=0;i<M;i++)
        scanf("%d", &B[i]);
    sort(A, A+N);
    sort(B, B+M);
    if(A[0]>B[M-1])
        ans=K;
    else
    {
        int sell=0;
        sell=K/A[0];
        ans=K-sell*A[0];
        ans+=sell*B[M-1];
    }
    printf("%d", ans);
}