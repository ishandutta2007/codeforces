#include <iostream>
#include <set>
#include <utility>

using namespace std;

set<pair<int,int> > toate;

int main()
{
    bool ok=true;

    int n,i,x,k;

    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x>>k;

        if(x>0)
            if(!toate.count(make_pair(x-1,k)))
            {
                ok=false;
                break;
            }
        toate.insert(make_pair(x,k));
    }

    if(ok)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}