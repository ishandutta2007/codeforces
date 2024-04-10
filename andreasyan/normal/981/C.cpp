#include <bits/stdc++.h>
using namespace std;
const int N=100005;

int n;
vector<int> a[N];

int main()
{
    cin>>n;
    for(int i=0;i<n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    int y=-1;
    for(int x=1;x<=n;++x)
    {
        if(a[x].size()>2)
        {
            if(y==-1)
                y=x;
            else
            {
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    if(y==-1)
        y=1;
    cout<<"Yes"<<endl;
    vector<int> ans;
    for(int x=1;x<=n;++x)
    {
        if(a[x].size()==1 && x!=y)
        {
            ans.push_back(x);
        }
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();++i)
    {
        cout<<y<<' '<<ans[i]<<endl;
    }
    return 0;
}