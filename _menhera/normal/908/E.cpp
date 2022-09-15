#include<bits/stdc++.h>
using namespace std;
char arr[51][1010];
int adj[1010][1010];
bool visit[1010];
int M, N;
int dfs(int x)
{
    if(visit[x]) return 0;
    visit[x] = true;
    int ans = 1;
    for(int i=0; i<M; ++i)
        if(adj[x][i] && !visit[i]) ans += dfs(i);
    return ans;
}
const int mod = 1e9+7;
int st[1010];
int comb[1010][1010];
int main()
{
    scanf("%d%d", &M, &N);
    for(int i=0; i<N; ++i) scanf("%s", arr[i]);
    for(int i=0; i<M; ++i)
        for(int j=0; j<i; ++j)
        {
            bool conn = true;
            for(int k=0; k<N; ++k)
                if(arr[k][i] != arr[k][j]) conn = false;
            if(conn) adj[i][j] = adj[j][i] = true;
        }
    comb[0][0] = 1;
    for(int i=1; i<=M; ++i)
    {
        comb[i][0] = comb[i][i] = 1;
        for(int j=1; j<i; ++j)
            comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % mod;
    }
    
    st[0] = 1; st[1] = 1;
    for(int n=2; n<=M; ++n)
    {
        long long ans = 0;
        for(int k=1; k<=n; ++k)
        {
            ans += 1LL*comb[n-1][k-1]*st[n-k]%mod;
        }
        st[n] = ans%mod;
    }
    
    
    int ans = 1;
    for(int i=0; i<M; ++i)
        if(!visit[i]) ans = (1LL* ans * st[dfs(i)])%mod;
    printf("%d\n", ans);
    return 0;
}