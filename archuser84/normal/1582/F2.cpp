///
///   MUDA MUDA MUDA
///
 
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")
typedef short ymm __attribute((vector_size(32),aligned(32)));

static const int N = 1e6+10;
static const short M = 1<<13;

static short a[N];
static ymm dp1[M/16], dp2[M/16];
int n;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    dp1[0][0] = 0;
    for(int i = 1; i < M; ++i)
        dp1[i/16][i&15] = M;
    for(int i = 0; i < n; ++i)
    {
        const short x = a[i];
        ymm shf; for(int z=0;z<16;++z) shf[z]=z^(x&15);
        for(int j = 0; j < M/16; ++j)
        {
            dp2[j^(x>>4)] = __builtin_shuffle(dp1[j], shf);
        }
        for(int j = 0; j < M/16; ++j)
            dp1[j] = dp2[j] < x && dp1[j] > x? x: dp1[j];
    }
    int ans = 0; for(int i = 0; i < M; ++i) if(dp1[i/16][i&15] < M) ++ans;
    cout << ans << '\n';
    for(int i = 0; i < M; ++i) if(dp1[i/16][i&15] < M) cout << i << ' ';
    cout << '\n';
}