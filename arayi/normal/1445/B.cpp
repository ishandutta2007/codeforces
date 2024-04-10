#include <bits/stdc++.h>
using namespace std;

int t, a, b, c, d;

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>d;
        cout<<max(a+b, c+d)<<endl;
    }
    return 0;
}