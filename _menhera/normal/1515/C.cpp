#pragma GCC target("avx2,popcnt")
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        int N, M, X;
        scanf("%d%d%d", &N, &M, &X);
        vector<int> H(N), ans(N);
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> Q;
        for(int i=1; i<=M; ++i) Q.emplace(0, i);
        for(int i=0; i<N; ++i)
        {
            scanf("%d", &H[i]);
            auto [h, v] = Q.top(); Q.pop();
            ans[i] = v; h += H[i];
            Q.emplace(h, v);
        }
        puts("YES");
        for(auto x: ans) printf("%d ", x);
        puts("");

    }
}