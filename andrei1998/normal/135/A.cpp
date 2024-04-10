#include <iostream>
#include <algorithm>

#define NMAX 100005
using namespace std;

int v[NMAX];
int ans[NMAX];
int n;

bool plin()
{
    bool ok=true;
    int i;

    for(i=2;i<=n;i++)
        if(v[i]!=v[1])
        {
            ok=false;
            break;
        }

    return ok;
}

int main()
{
    int i;
    cin>>n;

    for(i=1;i<=n;i++)
        cin>>v[i];

    if(n==1)
        if(v[1]>1)
        {
            cout<<"1\n";
            return 0;
        }
        else
        {
            cout<<"2\n";
            return 0;
        }

    if(plin())
    {
        for(i=1;i<=n;i++)
            ans[i]=v[i];

        ans[1]=1;

        if(v[1]==1)
            ans[n]=2;
        else
            ans[n]=v[n];

        cout<<ans[1];
        for(i=2;i<=n;i++)
            cout<<' '<<ans[i];
        cout<<'\n';

        return 0;
    }

    sort(v+1,v+n+1);
    for(i=2;i<n;i++)
    {
        if(v[i]==v[i-1] && v[i]==v[i+1])
            ans[i]=v[i];
        else if(v[i]>v[i-1])
            ans[i]=v[i-1];
        else if(v[i]<v[i+1])
            ans[i]=v[i];
    }

    ans[1]=1;
    if(v[n]==v[n-1])
        ans[n]=v[n];
    else
        ans[n]=v[n-1];

    cout<<ans[1];
    for(i=2;i<=n;i++)
        cout<<' '<<ans[i];
    cout<<'\n';

    return 0;
}