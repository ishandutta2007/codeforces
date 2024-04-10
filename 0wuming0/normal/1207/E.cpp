#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    cout<<'?';
    for(int i=1;i<=100;i++)cout<<' '<<i;
    cout<<endl;
    ll a,b=128;
    cin>>a;
    a=a/128*128;
    cout<<'?';
    for(int i=1;i<=100;i++)cout<<' '<<(b*b)-i*b;
    cout<<endl;
    cin>>b;
    cout<<'!'<<' '<<a+b%128<<endl;
    return 0;
}