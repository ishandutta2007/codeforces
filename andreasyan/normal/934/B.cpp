#include <iostream>
using namespace std;
const unsigned long long INF=1000000000000000000;

int main()
{
    int n;
    cin>>n;
    unsigned long long ans=0;
    if(n==1)
    {
        cout<<"6"<<endl;
        return 0;
    }
    while(1)
    {
        if(n==0 || ans>INF)
        {
            break;
        }
        if(n==1)
        {
            ans*=10;
            --n;
        }
        else
        {
            ans*=10;
            ans+=8;
            n-=2;
        }
    }
    if(ans>INF)
        cout<<"-1"<<endl;
    else
        cout<<ans<<endl;
    return 0;
}