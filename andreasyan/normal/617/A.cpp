#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    cin>>x;
    int ans=0;
    ans+=(x/5);
    x=x%5;
    ans+=(x/4);
    x=x%4;
    ans+=(x/3);
    x=x%3;
    ans+=(x/2);
    x=x%2;
    ans+=x;
    cout<<ans<<endl;
    return 0;
}