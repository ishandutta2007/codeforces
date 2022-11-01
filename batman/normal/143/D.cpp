#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (301*1000)
#define INF ((ll)1e15)

ll n,m,ans;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    if(n==2 || m==2) 
    {
        if(m>2)swap(n,m);
        ll k =4*((ll)(n/2)/2); 
        if(n%2==1 && (ll)(n/2)%2==1)k+=2;
        return cout<<n*m-k,0;
    }
    cout<<max(ans,max((ll)ceil((ld)n/3)*m,max((ll)ceil((ld)m/3)*n,(n%2==0 || m%2==0)?n*m/2:(n*m+1)/2)));
    return 0;
}