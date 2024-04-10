#include"bits/stdc++.h"
using namespace std;
int prime[1000006];
void solve(long long n)
{
    long long t=(long long)sqrt(double(n));
    if(n<=3)cout<<"NO"<<endl;
    else
    {
        long long z=-1;
        if((t+1)*(t+1)==n)z=t+1;t--;
        if((t+1)*(t+1)==n)z=t+1;t--;
        if((t+1)*(t+1)==n)z=t+1;t--;
        if(z==-1)cout<<"NO"<<endl;
        else
        {//cout<<prime[z]<<endl;
            if(prime[z])cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }
}
int main()
{
    for(int i=2;i<1000006;i++)
    {
        if(prime[i]==0)
        {
            for(int j=2;i*j<1000006;j++)prime[i*j]=i;
        }
    }//cout<<prime[995]<<endl;
    //solve(995*995);
    int n;
    cin>>n;
    while(n--)
    {
        long long t;
        cin>>t;
        solve(t);
    }
    return 0;
}