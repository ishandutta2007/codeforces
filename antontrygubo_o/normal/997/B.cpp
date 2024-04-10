#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n;
    cin>>n;
    ll result = 0;
    for (int a = 0; a<=8; a++)
    for (int b = 0; b<=8; b++)
    if ((a==0||b<=4)&&(a+b<=n))
    {
        result+=n+1-a-b;
    }
    cout<<result;
}