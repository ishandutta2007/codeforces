#include <bits/stdc++.h>
#pragma pack(1)

using namespace std;

#define div dskglksdl

const int MAXN=1e5+5;
const int MAXA=2e6+6;

int div[MAXA];
int val[MAXN], ans[MAXN], H[MAXN];
bool used[MAXN];
vector<int> G[MAXN];
vector<short> factors[MAXA];

void dfs(int x,int h)
{
    ans[x]=-2;
    used[x]=1;
    H[x]=h;
    int r2[300];
    for(int i=0;i<factors[val[x]].size();i++)
    {
        int a=factors[val[x]][i];
        int b=val[x]/factors[val[x]][i];
        if(a==1) a=b;
        if(a<=1 || b<=1) continue;
        if(H[div[a]]>H[ans[x]]) ans[x]=div[a];
        if(H[div[b]]>H[ans[x]]) ans[x]=div[b];
        r2[2*i]=div[a];
        r2[2*i+1]=div[b];
        div[a]=x;
        div[b]=x;
            //}
    }
    for(int i=0;i<G[x].size();i++)
        if(!used[G[x][i]]) dfs(G[x][i],h+1);
    for(int i=0;i<factors[val[x]].size();i++)
    {
        int a=factors[val[x]][i];
        int b=val[x]/factors[val[x]][i];
        div[a]=r2[2*i];
        div[b]=r2[2*i+1];
    }

}

main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin>>n>>q;

    for(int i=1;i*i<MAXA;i++)
        for(int j=i*i;j<MAXA;j+=i)
            factors[j].push_back(i);
    for(int i=0;i<n;i++) cin>>val[i];
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    fill(div,div+MAXA,-2);
    fill(H,H+MAXN,0);
    fill(used,used+MAXN,0);
    dfs(0,1);
    while(q--)
    {
        int t,x;
        cin>>t>>x;
        x--;
        if(t==1)
        {
            cout<<ans[x]+1<<endl;
        }
        else
        {
            int T;
            cin>>T;
            val[x]=T;
            fill(div,div+MAXA,-2);
            fill(H,H+MAXN,0);
            fill(used,used+MAXN,0);
            dfs(0,1);
        }
    }
}