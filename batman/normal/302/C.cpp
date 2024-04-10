#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define INF ((ll)1e9)
#define N (333)

ll n,m,a[N],num;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    m=2*n-1;
    for(int i=0;i<m;i++)
    {
        cin>>a[i];  
        if(a[i]<0)num++;
    }
    if(num%2==0 || n%2==1)
    {
        ll sum=0;
        for(int i=0;i<m;i++)
            sum+=abs(a[i]);
        return cout<<sum,0; 
    }
    ll mini=INF,sum=0;
    for(int i=0;i<m;i++)
        sum+=abs(a[i]),mini=min(mini,abs(a[i]));
    cout<<sum-2*mini;   
    
    
    
    return 0;
}