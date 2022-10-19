#include"bits/stdc++.h"
using namespace std;
int main()
{
    long long n;
    cin>>n;
    long long m=min(1000000ll,n-1);
    int ans=0;
    for(int i=2;i<=m;i++)
        if(n%i==0)
        {
            while(n%i==0)n/=i;
            if(n==1)cout<<i<<endl;
            else cout<<1<<endl;
            return 0;
        }
    cout<<n<<endl;
    return 0;
}