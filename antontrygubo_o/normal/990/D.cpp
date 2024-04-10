#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 998244353;
const ll MAX = 100000000000;

int main()
{
ios_base::sync_with_stdio(false);
int n, a, b;
cin>>n>>a>>b;
if (a!=1&&b!=1) {cout<<"NO"; return 0;}
if (n==2&&a+b!=3) {cout<<"NO"; return 0;}
if (n==3&&a==1&&b==1) {cout<<"NO"; return 0;}
cout<<"YES"<<endl;
if (b==1)
{
    int t = n-a;
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<n; j++)
        {
            if (fabs(i-j)==1&&i<=t&&j<=t) cout<<1;
            else cout<<0;
        }
        cout<<endl;
    }
    return 0;
}

if (a==1)
{
    int t = n-b;
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<n; j++)
        {
            if (i==j) cout<<0;
            else if (fabs(i-j)==1&&i<=t&&j<=t) cout<<0;
            else cout<<1;
        }
        cout<<endl;
    }
}

}