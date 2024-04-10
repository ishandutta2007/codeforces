#include<bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9+7;


// x: add, y: remove
int solve(int N, int P, int K, char* buf, int x, int y)
{
    vector<vector<int> > V(K);
    for(int i=0; i<N; ++i)
    {
        int v = '1'-buf[i];
        int p = V[i%K].empty() ? 0 : V[i%K].back();
        V[i%K].push_back(p+v);
    }
    int ans = (int)2e9;
    for(int p=P-1; p<N; ++p)
    {
        int rmcost = (p-(P-1))*y;
        int idx = p/K-1;
        int addv = idx == -1 ? 0: V[p%K][idx];
        int tv = V[p%K].back() - addv;
        ans = min(ans, rmcost+tv*x);
    }
    return ans;
}

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        int N, P, K; scanf("%d%d%d", &N, &P, &K);
        char buf[101010];
        int x, y;
        scanf("%s%d%d", buf, &x, &y);
        printf("%d\n", solve(N, P, K, buf, x, y));
    }
}