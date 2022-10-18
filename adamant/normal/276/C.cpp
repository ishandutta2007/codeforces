#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <numeric>
 
using namespace std;
 
#define ll long long
 
int main(int argc, char *argv[])
{
    ll n,q;
    
    cin>>n>>q;
    
    ll*a=new ll[n];
    
    ll *l=new ll[q],*r=new ll[q];
    
    for(ll i=0;i<n;i++)
    cin>>a[i];
sort(a,a+n);
reverse(a,a+n);
    for(ll i=0;i<q;i++)
    {
    cin>>l[i]>>r[i];
    }
    sort(l,l+q);
    sort(r,r+q);
 ll*it=new ll[n];
 for(ll i=0;i<n;i++)
 {
        it[i]=(q-(lower_bound(r,r+q,i+1)-r))-(q-(upper_bound(l,l+q,i+1)-l));
        
 }
 sort(it,it+n);
 reverse(it,it+n);
 ll ans=0;
 for(ll i=0;i<n;i++)
 ans+=a[i]*it[i];
 cout<<ans<<endl;
    return EXIT_SUCCESS;
}