#pragma GCC target("avx2,popcnt")
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        int N, X; scanf("%d%d", &N, &X);
        vector<int> V(N);
        for(int i=0; i<N; ++i)
            scanf("%d", &V[i]);
        int s = 0;
        bool ans = true;
        for(int i=0; i<N; ++i)
        {
            s += V[i];
            if(s == X)
            {
                if(i == N-1) ans = false;
                else swap(V[i], V[i+1]);
            }
        }
        if(!ans) puts("NO");
        else {
            puts("YES");
            for(auto x: V) printf("%d ", x);
            puts("");
        }
    }
    return 0;
}