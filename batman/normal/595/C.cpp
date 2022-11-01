#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (201*1000)
#define INF ((ll)1e9)

ll n,a[N],ans=INF;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n/2;i++)  
        ans=min(ans,abs(a[i]-a[i+n/2]));
    cout<<ans;  
    return 0;
}