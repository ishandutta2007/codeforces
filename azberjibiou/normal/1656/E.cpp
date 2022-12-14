#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
#define fir first
#define sec second
#define pii pair<int, int>
#define pll pair<ll, ll>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
typedef long long ll;
using namespace std;
int dx[4]={0, 1, 0, -1}, dy[4]={1, 0, -1 , 0};
const int mxN=150000;
const int mxM=1010;
const int mxK=2000000;
const int MOD=1000000007;
const ll INF=1e15;
const ll P1=1000000007;
const ll P2=1000000009;
int N;
vector <int> v[mxN];
int dep[mxN], sub[mxN];
int ans[mxN];
void dfs(int now, int pre)
{
    sub[now]=0;
    for(int nxt : v[now])   if(nxt!=pre)
    {
        dep[nxt]=dep[now]+1;
        dfs(nxt, now);
        sub[now]+=sub[nxt];
    }
    if(dep[now]==0)
    {
        ans[now]=-sub[now];
    }
    else if(dep[now]%2==0)
    {
        ans[now]=-sub[now]+1;
    }
    else
    {
        ans[now]=-sub[now]-1;
    }
    sub[now]=(dep[now]%2==1 ? -1 : 1);
}
int main()
{
    gibon
    int T;
    cin >> T;
    while(T--)
    {
        cin >> N;
        for(int i=1;i<=N;i++)   v[i].clear();
        for(int i=1;i<N;i++)
        {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dep[1]=0;
        dfs(1, -1);
        for(int i=1;i<=N;i++)   cout << ans[i] << " ";
        cout << '\n';
    }
}