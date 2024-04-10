#include <bits/stdc++.h>
using namespace std;
const int N=100005;

int n,m;
vector<int> a[N],b[N];

int ans[N];

bool c[N];

int d[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        b[y].push_back(x);
    }
    priority_queue<int> q;
    for(int i=1;i<=n;++i)
    {
        d[i]=a[i].size();
        if(!d[i])
            q.push(i);
    }
    for(int i=n;i>=1;--i)
    {
        int x;
        do
        {
            x=q.top();
            q.pop();
        }while(c[x]);
        ans[x]=i;
        c[x]=true;
        for(int j=0;j<b[x].size();++j)
        {
            int h=b[x][j];
            d[h]--;
            if(!d[h])
                q.push(h);
        }
    }
    for(int i=1;i<=n;++i)
        cout<<ans[i]<<' ';
    cout<<endl;
    return 0;
}