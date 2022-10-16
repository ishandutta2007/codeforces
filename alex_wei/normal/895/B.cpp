#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,x,k,a[100002],s;
int main()
{
    cin>>n>>x>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++){
        ll l=(a[i]%x?(a[i]/x+k)*x:a[i]+(k-1)*x),r=(a[i]%x?(a[i]/x+k+1)*x-1:a[i]+k*x-1);
        if(!k){
            if(a[i]%x==0)continue;
            else l=a[i];
        }
        s+=lower_bound(a,a+n,r+1)-lower_bound(a,a+n,l);
    }
    cout<<s;
    return 0;
}