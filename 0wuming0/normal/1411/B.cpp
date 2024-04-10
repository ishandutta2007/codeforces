#include"bits/stdc++.h"
using namespace std;
bool ju(long long a)
{
    int b=a%60480;
    int t;
    while(a)
    {
        t=a%10;
        if(t&&b%t)return 0;
        a/=10;
    }
    return 1;
}
int main()
{
    int t=1;
    //for(int i=4;i<10;i++)t*=i;
    //cout<<t<<endl;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        for(;;n++)
        {
            if(ju(n))break;
        }
        cout<<n<<endl;
    }
    return 0;
}