#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (301*1000)
#define INF ((ll)1e15)

ll n,mini=INF,maxi;
vector <ll> v;

void check(ll x)
{
    ll p=n/x;
    for(ll i=1;i*i<=p;i++)
    if(p%i==0)
    {
        ll a[3]={x,i,p/i};
        for(int j=0;j<3;j++)
            for(int k=0;k<3;k++)
                for(int q=0;q<3;q++)
                    if(j!=k && j!=q && k!=q)
                    {
                        //if(mini>(a[j]+1)*(a[k]+2)*(a[q]+2)-a[j]*a[k]*a[q])
                            //cout<<a[j]<<" "<<" "<<a[k]<<" "<<a[q]<<"\n";
                        mini=min(mini,(a[j]+1)*(a[k]+2)*(a[q]+2)-a[j]*a[k]*a[q]),maxi=max(maxi,(a[j]+1)*(a[k]+2)*(a[q]+2)-a[j]*a[k]*a[q]);
                    }
                        
        
    }
}

int main()
{ 
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i*i<=n;i++)
        if(n%i==0)
            v.push_back(i),v.push_back(n/i);
    for(int i=0;i<v.size();i++)
        check(v[i]);        
    cout<<mini<<" "<<maxi;
    return 0;
}