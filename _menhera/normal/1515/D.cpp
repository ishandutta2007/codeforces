#pragma GCC target("avx2,popcnt")
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        int N, L, R; scanf("%d%d%d", &N, &L, &R);
        vector<int> lcnt(N), rcnt(N);
        for(int i=0; i<L; ++i)
        {
            int x; scanf("%d", &x); --x;
            lcnt[x]++;
        }
        for(int i=0; i<R; ++i)
        {
            int x; scanf("%d", &x); --x;
            rcnt[x]++;
        }
        int ans = 0;
        for(int i=0; i<N; ++i)
        {
            int v = min(lcnt[i], rcnt[i]);
            lcnt[i] -= v; L -= v;
            rcnt[i] -= v; R -= v;
            while(L < R && rcnt[i] >= 2)
            {
                rcnt[i] -= 2; R -= 2;
                ++ans;
            }
            while(L > R && lcnt[i] >= 2)
            {
                lcnt[i] -= 2; L -= 2;
                ++ans;
            }
        }
        ans += abs(R-L)/2;
        ans += (R+L)/2;
        printf("%d\n", ans);
    }
}