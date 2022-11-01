#include <bits/stdc++.h>
using namespace std;
#define INF ((ll)1e15)
#define MOD ((ll)1e9+7)
#define N (301*1000)
#define ll long long
#define ld long double

ll n,a[N],mini[N],ans;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    mini[n]=INF;
    for(int i=n-1;i>=0;i--)
        mini[i]=min(a[i],mini[i+1]);
    ll maxi=0;  
    for(int i=0;i<n;i++)
    {
        maxi=max(maxi,a[i]);
        if(maxi<=mini[i+1])
            ans++,maxi=0;
    }   
    cout<<ans;
    
    return 0;
}