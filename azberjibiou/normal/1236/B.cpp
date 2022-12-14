#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long a, b;
long long power(long long a, long long b)
{
    int Bt[1010]={};
    int idx=0;
    while(b!=0)
    {
        Bt[idx++]=b%2;
        b/=2;
    }
    long long B2[1010]={};
    B2[0]=a;
    for(int i=1;i<=idx+1;i++)
    {
        B2[i]=B2[i-1]*B2[i-1];
        B2[i]%=mod;
    }
    long long ans=1;
    for(int i=0;i<=idx+1;i++)
    {
        if(Bt[i]==1)
        {
            ans*=B2[i];
            ans%=mod;
        }
    }
    return ans;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> a >> b;
    cout << (power(power(2, b)-1, a));
}