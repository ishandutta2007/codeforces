#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;

int n, l, x, y;
int a[N];

int32_t main()
{
    IOS;
    cin>>n>>l>>x>>y;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int checkx=0, checky=0;
    for(int i=1;i<=n;i++)
    {
        auto it=lower_bound(a+i, a+n+1, a[i]+x);
        if(*it==a[i]+x)
            checkx=1;
        it=lower_bound(a+i, a+n+1, a[i]+y);
        if(*it==a[i]+y)
            checky=1;
    }
    set<int> reqdx, reqdy;
    if(!checkx)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]+x<=l)
                reqdx.insert(a[i]+x);
            if(a[i]-x>=0)
                reqdx.insert(a[i]-x);
        }
    }
    if(!checky)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]+y<=l)
                reqdy.insert(a[i]+y);
            if(a[i]-y>=0)
                reqdy.insert(a[i]-y);
        }
    }
    if(checkx&checky)
    {
        cout<<"0";
        return 0;
    }
    if(checkx|checky)
    {
        cout<<"1"<<endl;
        if(!checkx)
            cout<<*(reqdx.begin());
        else
            cout<<*(reqdy.begin());
        return 0;
    }
    for(auto it:reqdx)
    {
        if(reqdy.find(it)!=reqdy.end())
        {
            cout<<1<<endl;
            cout<<it;
            return 0;
        }
    }
    cout<<2<<endl;
    cout<<*(reqdx.begin())<<" "<<*(reqdy.begin());
    return 0;
}