#include <iostream>
#include <vector>
using namespace std;
const int N=150003;

int n,m,k;
vector<int> a[N];
pair<int,int> b[N];

long long d[N];
long long q[N];

int c[N];
void dfs(int x,int u)
{
    c[x]=u;
    for(int i=0;i<a[x].size();++i)
    {
        int h=a[x][i];
        if(!c[h])
            dfs(h,u);
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        cin>>b[i].first>>b[i].second;
        a[b[i].first].push_back(b[i].second);
        a[b[i].second].push_back(b[i].first);
    }
    int k=1;
    for(int i=1;i<=n;++i)
    {
        if(!c[i])
        {
            dfs(i,k);
            ++k;
        }
        q[c[i]]++;
    }
    for(int i=0;i<m;++i)
        d[c[b[i].first]]++;
    for(int i=1;i<k;++i)
    {
        if(d[i]!=(q[i]*(q[i]-1))/2)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}