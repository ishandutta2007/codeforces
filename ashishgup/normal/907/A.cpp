#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
    IOS;
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    int car=-1;
    for(int i=d;i<=2*d;i++)
    {
        if(c<=i&&i<=2*c)
        {
            car=i;
            break;
        }
    }
    if(car==-1)
    {
        cout<<"-1";
        return 0;
    }
    int cura=d;
    int curb=2*b;
    if(!(2*cura<curb))
    {
        cout<<"-1";
        return 0;
    }
    cout<<2*a<<endl;
    cout<<2*b<<endl;
    cout<<car;
}