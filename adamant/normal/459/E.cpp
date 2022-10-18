#include <bits/stdc++.h>
#pragma pack(1)

using namespace std;

#define TASK "test"

struct edge
{
    int a,b,c;
};

int main()
 {
    #ifndef ONLINE_JUDGE
    freopen(TASK".in","r",stdin);
    freopen(TASK".out","w",stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<edge> G(m);
    for(auto &it:G) cin>>it.a>>it.b>>it.c,it.a--,it.b--;
    sort(G.begin(),G.end(),[](edge a,edge b){return a.c>b.c;});
    vector<int> ans[2];
    ans[0].assign(n,0);
    ans[1].assign(n,0);
    vector<int> E[2];
    E[0].resize(n);
    E[1].resize(n);
    int ANS=0;
    for(auto &it:G)
    {
        int cur=1;
        if(it.c==E[0][it.b]) cur+=ans[1][it.b];
        else cur+=ans[0][it.b];
        if(cur>ans[0][it.a])
            if(E[0][it.a]==it.c) ans[0][it.a]=cur;
            else ans[1][it.a]=ans[0][it.a], E[1][it.a]=E[0][it.a], E[0][it.a]=it.c, ans[0][it.a]=cur;
        else if(cur>ans[1][it.a] && it.c!=E[0][it.a]) E[1][it.a]=it.c,ans[1][it.a]=cur;
        ANS=max(ANS,ans[0][it.a]);

    }
    cout<<ANS<<endl;
 }