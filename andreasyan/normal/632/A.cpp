#include <iostream>
using namespace std;

string a[100];
int main()
{
    long long n,p;
    cin>>n>>p;
    long long m=0;
    for(int i=0;i<n;++i)
        cin>>a[i];
    long long ans=0;
    for(int i=n-1;i>=0;--i)
    {
        if(a[i]=="half")
        {
            ans+=(m*p);
            m*=2;
        }
        else
        {
            ans+=(m*p);
            ans+=(p/2);
            m*=2;
            ++m;
        }
    }
    cout<<ans<<endl;
    return 0;
}