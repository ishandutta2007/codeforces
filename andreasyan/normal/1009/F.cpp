#include <bits/stdc++.h>
using namespace std;
const int N=1000006;

int n;
vector<int> a[N];

int ans[N];

int maxu[N],maxi[N];
map<int,int> b[N];
int c[N];
void dfs(int x,int p)
{
    c[x]=c[p]+1;
    b[x][c[x]]++;
    maxi[x]=c[x];
    maxu[x]=1;
    for(int i=0;i<a[x].size();++i)
    {
        int h=a[x][i];
        if(h==p)continue;
        dfs(h,x);
        if(b[h].size()>b[x].size())
        {
            swap(b[h],b[x]);
            swap(maxu[h],maxu[x]);
            swap(maxi[h],maxi[x]);
        }
        for(map<int,int>::iterator it=b[h].begin();it!=b[h].end();++it)
        {
            b[x][it->first]+=b[h][it->first];
            if(b[x][it->first]>maxu[x])
            {
                maxu[x]=b[x][it->first];
                maxi[x]=it->first;
            }
            else if(b[x][it->first]==maxu[x] && it->first<maxi[x])
            {
                maxi[x]=it->first;
            }
        }
    }
    ans[x]=maxi[x]-c[x];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1,0);
    for(int i=1;i<=n;++i)
        cout<<ans[i]<<endl;
    return 0;
}