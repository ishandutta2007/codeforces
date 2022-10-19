#include"bits/stdc++.h"
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ans=0;
    while(n--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a+b+c>=2)ans++;
    }
    cout<<ans<<endl;
    return 0;
}