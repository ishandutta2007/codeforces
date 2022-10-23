#include <iostream>

using namespace std;

int main()
{
    int n,s,a[1001],b[1001],t=0;
    bool kt=false;
    cin>>n>>s;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        if (a[i]==1) t=i;
    }
    for (int i=1;i<=n;i++) cin>>b[i];
    if (s==1) cout<<"YES"; else
    if (a[1]==1 && a[s]==1) cout<<"YES"; else
    if (a[1]==1 && b[s]==1)
    {
        for (int i=s+1;i<=n;i++)
            if (a[i]==1 && b[i]==1)
            {
                kt=true;
                break;
            }
        if (kt) cout<<"YES"; else cout<<"NO";
    }
    else cout<<"NO";
    return 0;
}