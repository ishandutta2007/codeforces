#include <bits/stdc++.h>

using namespace std;

main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    int x[n][m];
    for(auto &t:x)
        for(auto &it:t)
            cin>>it;
    vector<bool> blocked(k,0);
    vector<bool> use;
    vector<int> block(n,0);
    for(int i=0;i<m;i++)
    {
        use.assign(k,0);
        for(int j=0;j<n;j++)
        {
            if(!x[j][i] || block[j])continue;
            if(use[x[j][i]])
                blocked[x[j][i]]=1;
            use[x[j][i]]=1;
        }
        for(int j=0;j<n;j++)
            if(blocked[x[j][i]] && !block[j])
                block[j]=i+1;
    }
    for(auto it:block)
        cout<<it<<"\n";
}