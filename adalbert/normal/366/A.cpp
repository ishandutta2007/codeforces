#include <bits/stdc++.h>
using namespace std;
long long a,b,c,d,n;
int main()
{
    cin>>n;
    for (int i=1;i<=4;i++)
    {
        cin>>a>>b>>c>>d;
        if (min(a,b)+min(d,c)<=n)
        {
            cout<<i<<' ';
            cout<<min(a,b)<<' ';
            cout<<n-min(a,b);
            return(0);
        }
    }
    cout<<-1;
}