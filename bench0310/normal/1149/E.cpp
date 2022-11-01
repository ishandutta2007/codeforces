#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> h(n+1,0);
    for(int i=1;i<=n;i++) cin >> h[i];
    vector<int> v[n+1];
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    vector<int> t(n+1,0);
    vector<int> mex(n+1,-1);
    vector<int> lvl[n+1];
    vector<int> x(n+1,0);
    function<void(int)> dfs=[&](int a)
    {
        for(int to:v[a]) if(mex[to]==-1) dfs(to);
        for(int to:v[a]) t[mex[to]]=1;
        mex[a]=0;
        while(t[mex[a]]==1) mex[a]++;
        lvl[mex[a]].push_back(a);
        x[mex[a]]^=h[a];
        for(int to:v[a]) t[mex[to]]=0;
    };
    for(int i=1;i<=n;i++) if(mex[i]==-1) dfs(i);
    int p=-1;
    for(int i=0;i<=n;i++) if(x[i]!=0) p=i;
    if(p!=-1)
    {
        cout << "WIN\n";
        int a=0;
        for(int b:lvl[p]) if(h[b]>(h[b]^x[p])) a=b;
        h[a]^=x[p];
        for(int to:v[a])
        {
            h[to]^=x[mex[to]];
            x[mex[to]]=0;
        }
        for(int i=1;i<=n;i++) cout << h[i] << " \n"[i==n];
    }
    else cout << "LOSE\n";
    return 0;
}