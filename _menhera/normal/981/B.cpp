#include<bits/stdc++.h>
using namespace std;
map<int, int> M;
int main()
{
    int N; scanf("%d", &N);
    for(int i=0; i<N; ++i)
    {
        int x, y; scanf("%d%d", &x, &y);
        M[x] = max(M[x], y);
    }
    scanf("%d", &N);
    for(int i=0; i<N; ++i)
    {
        int x, y; scanf("%d%d", &x, &y);
        M[x] = max(M[x], y);
    }
    long long ans = 0;
    for(auto y: M)
    {
        ans += y.second;
    }
    printf("%lld\n", ans);

}