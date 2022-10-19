#include"bits/stdc++.h"
using namespace std;
int gcd(int n,int m)
{
    if(n==0||m==0)return n+m;
    return gcd(min(n,m),max(n,m)%min(n,m));
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int t=gcd(m,k);
    m/=t;k/=t;
    if(k==1||k==2)
    {
        cout<<"YES"<<endl;
        cout<<"0 0"<<endl;
        printf("%d %d\n",n,0);
        printf("%d %d\n",0,m*2/k);
    }
    else
    {
        t=gcd(n,k);
        n/=t;k/=t;
        if(k==1||k==2)
        {
            cout<<"YES"<<endl;
            cout<<"0 0"<<endl;
            printf("%d %d\n",n*2/k,0);
            printf("%d %d\n",0,m);
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}