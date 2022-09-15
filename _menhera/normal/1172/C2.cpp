#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;


int ipow(int a, int b)
{
    if(b==0) return 1;
    int ans = ipow(a, b/2); ans = 1LL*ans*ans%MOD;
    if(b&1) ans = 1LL*ans*a%MOD;
    return ans;
}
int modInv(int a){ return ipow(a, MOD-2); }

int N, M, A[202020], W[202020], f[3030][3030], g[3030][3030];
int main()
{
    scanf("%d%d", &N, &M);
    int hsum = 0, lsum = 0;
    for(int i=1; i<=N; ++i) scanf("%d", A+i);
    for(int i=1; i<=N; ++i) scanf("%d", W+i);
    for(int i=1; i<=N; ++i)
        if(A[i] == 0) hsum += W[i];
        else lsum += W[i];

    for(int i=M; i>=0; --i)
    {
        f[i][M-i] = g[i][M-i] = 1;
        for(int j=M-i-1; j>=0; --j)
        {
            f[i][j] = (1LL*(lsum+i+1)*f[i+1][j] + 1LL*(hsum-j)*f[i][j+1])%MOD*ipow(lsum+hsum+i-j, MOD-2)%MOD;
            g[i][j] = (1LL*(lsum+i)*g[i+1][j] + 1LL*(hsum-j-1)*g[i][j+1])%MOD*ipow(lsum+hsum+i-j, MOD-2)%MOD;
        }
    }

    for(int i=1; i<=N; ++i)
        if(A[i] == 0) printf("%lld\n", 1LL*W[i]*g[0][0]%MOD);
        else printf("%lld\n", 1LL*W[i]*f[0][0]%MOD);

    return 0;

}