#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int getreduced(int k)
{
    int ans=0;
    int pow=1;
    while(k>0)
    {
        if(k%10)
        {
            ans=(ans + pow*(k%10));
            pow*=10;
        }
        k/=10;
    }
    return ans;
}

int32_t main()
{
    IOS;
    int a, b;
    cin>>a>>b;
    int c=a+b;
    a=getreduced(a);
    b=getreduced(b);
    c=getreduced(c);
    if(c==(a+b))
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}