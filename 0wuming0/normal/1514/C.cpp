#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll mod=1e9+7;
#define gcd __gcd
ll save[200005],nn;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        if(gcd(i,n)==1)
        {
            save[nn++]=i;
        }
    }
    int now=1;
    for(int i=0;i<nn;i++)
    {
        now=now*save[i]%n;
    }
    if(now==1)
    {
        cout<<nn<<endl;
        for(int i=0;i<nn;i++)printf("%lld%c",save[i]," \n"[i==nn-1]);
    }
    else
    {
        for(int i=0;i<nn;i++)if(save[i]==now)
        {
            swap(save[i],save[nn-1]);
            nn--;
            break;
        }
        cout<<nn<<endl;
        for(int i=0;i<nn;i++)printf("%lld%c",save[i]," \n"[i==nn-1]);
    }
    return 0;
}