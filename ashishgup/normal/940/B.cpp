#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n, k, a, b;
int ans=0;

void reduce()
{
    ans+=(a*(n%k));
    n-=(n%k);
    if(n==1)
        return;
    int newnum=n/k;
    int subt=n-newnum;
    if(subt * a > b)
    {
        ans+=b;
        n=newnum;
    }
    else
    {
        ans+=(n-1)*a;
        n=1;
    }
}

int32_t main()
{
    cin>>n>>k>>a>>b;
    while(n>1)
    {
        reduce();
    }
    cout<<ans;
    return 0;
}