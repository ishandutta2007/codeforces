#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        for(long long i=1;i*i*i<n;i++)
        {
            long long x=n-i*i*i;
            long long q=(long long)pow(x+1.0,1.0/3);
            if(q*q*q==x)
            {
                cout<<"YES"<<endl;
                goto ne;
            }
        }
        cout<<"NO"<<endl;
        ne:;
    }
    return 0;
}