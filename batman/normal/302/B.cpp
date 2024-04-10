#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define INF ((ll)1e9)
#define N (101*1000)

ll n,m,a[N],p,q,pass;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        ll c,t;
        cin>>c>>t;
        a[i]=c*t;
    }
    for(int i=0;i<m;i++)
    {
        ll x;
        cin>>x;
        ll pass2=x;
        x-=pass;
        while(x>0)
        {
            if(a[p]-q<x)
                x-=a[p]-q,p++,q=0;
            else
                q+=x,x=0;   
        }
        pass=pass2;
        cout<<p+1<<"\n";
    }
    
    return 0;
}