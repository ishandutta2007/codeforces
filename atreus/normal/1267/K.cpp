// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll C[25][25];
int main()
{
    for (int i = 0; i < 25; i ++)
    {
        C[0][i] = C[i][i] = 1;
        for (int j = 1; j < i; j ++)
            C[j][i] = C[j - 1][i - 1] + C[j][i - 1];
    }
    ll q;
    scanf("%lld", &q);
    for (; q; q --)
    {
        ll n, k;
        vector < ll > A(30, 0);
        scanf("%lld", &n);
        for (k = 2; n != 0; k ++)
            A[(int)(n % k)] ++, n /= k;
        k --;
        ll tot = 1, tot2 = 1, Cnt = 1;
        for (ll kk = k; kk > 1; kk --, Cnt ++)
            tot *= C[A[kk - 1]][Cnt], Cnt -= A[kk - 1];
        if (!A[0] || A[k - 1]) tot2 = 0;
        else A[0] --;
        Cnt = 1;
        for (ll kk = k - 1; kk > 1; kk --, Cnt ++)
            tot2 *= C[A[kk - 1]][Cnt], Cnt -= A[kk - 1];
        tot -= tot2; tot --;
        printf("%lld\n", tot);
    }
    return 0;
}