#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (301*1000)
#define INF ((ll)1e9)

ll n,m,a[N],ans;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    for(int i=n-1;i>=0;i--)
    {
        ans++;
        m-=a[i];
        if(m<=0)
            break;
    }
    cout<<ans;
        
    return 0;
}