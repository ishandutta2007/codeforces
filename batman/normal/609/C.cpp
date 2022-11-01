#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (301*1000)
#define INF ((ll)1e9)

ll n,a[N],sum,ans;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++)
        ans+=max(sum/n+(i+(sum%n)>=n)-a[i],0ll);    
    cout<<ans;
    
    return 0;
}