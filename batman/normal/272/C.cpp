#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define INF ((ll)1e9)
#define N (301*1000)

ll n,a[N],m,p,x;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    cin>>m;
    while(m--)
    {
        ll w,h;
        cin>>w>>h;
        w--;
        if(w>p)
        {
            if(a[w]>=a[p]+x)cout<<a[w]<<"\n",p=w,x=h;
            else cout<<a[p]+x<<"\n",x+=h;
        }
        else
            cout<<a[p]+x<<"\n",x+=h;    
    }
    return 0;
}