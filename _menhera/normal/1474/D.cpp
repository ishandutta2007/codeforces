#include<bits/stdc++.h>
using namespace std;



bool can(long a, long b, long c, long d)
{
    b -= a; if(b < 0) return false;
    c -= b; if(c < 0) return false;
    d -= c;
    return d == 0;
}


int main()
{
    int T; scanf("%d", &T); while(T--)
    {
        int N; scanf("%d", &N);
        vector<long> A(N+2), B(N+2), C(N+2);
        vector<bool> nb(N+2), nc(N+2);
        for(int i=1; i<=N; ++i) scanf("%ld", &A[i]);
        B[1] = A[1]; C[N] = A[N];
        for(int i=2; i<=N; ++i)
        {
            B[i] = A[i] - B[i-1];
            if(B[i] < 0 || nb[i-1]) nb[i] = true;
        }
        for(int i=N-1; i>=1; --i)
        {
            C[i] = A[i] - C[i+1];
            if(C[i] < 0 || nc[i+1]) nc[i] = true;
        }
        
        // B[i] A[i+1] A[i+2] C[i+3]
        bool ok = false;
        for(int i=0; i<N-1; ++i)
        {
            if(
                !nb[i] && !nc[i+3] &&
                (can(B[i], A[i+1], A[i+2], C[i+3]) || can(B[i], A[i+2], A[i+1], C[i+3]))
            )
            {
                ok = true;
                break;
            }
        }
        if(ok) puts("YES");
        else puts("NO");
    }
}