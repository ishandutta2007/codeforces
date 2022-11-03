#include <bits/stdc++.h>
#define fin freopen("ladder.in","r",stdin)
#define fout freopen("ladder.out","w",stdout)
using namespace std;
int k,a[10000],dp[10000],n,ans,h;
const int maxlongint = numeric_limits <int> :: max();
int main()
{
//	fin;
//	fout;

    cin>>n>>h;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        if (a[i]>h) ans=ans+2 ; else ans++;
    }
    cout<<ans;
}