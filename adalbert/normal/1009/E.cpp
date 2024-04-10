#include <bits/stdc++.h>
#define pb push_back
#define fir first
#define sec second
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int step[1100000];
int a[1100000];
const int md=998244353;

signed main()
{
    fast;
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];

    int ans=0;
    step[0]=1;
    for (int i=1;i<=n;i++)
        step[i]=step[i-1]*2%md;

    for (int i=1;i<=n;i++)
    {
        if (i!=n)
            ans+=(n-i)*step[n-i-1]%md*a[i]%md;
        ans%=md;
        ans+=a[i]*step[n-i]%md;
        ans%=md;
    }

    cout<<ans;
}
/*
*/