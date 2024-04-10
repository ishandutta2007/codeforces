#include"bits/stdc++.h"
using namespace std;
int q[202];
int gcd(int i,int j)
{
    if(i==0||j==0)return i+j;
    return gcd(j,i%j);
}
int main()
{
    for(int i=0;i<202;i++)q[i]=i*i;
    int m;
    cin>>m;
    int ans=0;
    for(int i=1;i<202;i++)for(int j=i;j<202;j++)
    {
        if(gcd(i,j)!=1)continue;
        if((i%2)!=(j%2))
        {
            int a=i*j*2;
            int c=(q[i]+q[j]);
            int b=(q[j]-q[i]);
            if(a<=b&&b<=c&&1<=a&&c<=m)
            {
                //cout<<a<<" "<<b<<" "<<c<<endl;
                ans+=m/c;
            }
            continue;
        }
        int a=i*j;
        int c=(q[i]+q[j])/2;
        int b=(q[j]-q[i])/2;
        if(a<=b&&b<=c&&1<=a&&c<=m)
        {
            //cout<<a<<" "<<b<<" "<<c<<endl;
            ans+=m/c;
        }
    }
    cout<<ans<<endl;
    return 0;
}