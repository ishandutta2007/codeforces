#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=200005;

int n,m;
int a[N];

int dist(int x,int y)
{
    if(x<y)
        return y-x;
    else
        return (m-x)+y;
}

vector<int> b[N];
int32_t main()
{
    cin>>n>>m;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        b[a[i]%m].push_back(i);
    }
    set<int> v;
    for(int i=0;i<m;++i)
    {
        if(b[i].size()<(n/m))
            v.insert(i);
    }
    int ans=0;
    for(int i=0;i<m;++i)
    {
        while(b[i].size()>(n/m))
        {
            set<int>::iterator it=v.lower_bound(i+1);
            if(it==v.end())
                it=v.begin();
            a[b[i].back()]+=dist(i,*it);
            ans+=dist(i,*it);
            b[*it].push_back(b[i].back());
            b[i].pop_back();
            if(b[*it].size()==(n/m))
                v.erase(*it);
            if(b[i].size()==(n/m))
                v.erase(i);
        }
    }
    cout<<ans<<endl;
    for(int i=0;i<n;++i)
        cout<<a[i]<<' ';
    cout<<endl;
    return 0;
}