#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n,ans=0,k[100*1001],a[5];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>k[i];
        a[k[i]]++;
    }
    ans+=min(a[1],a[3])+a[2]/2+a[4]+(a[2]%2);
    
    if(a[3]>a[1])
        ans+=a[3]-a[1];
    a[1]-=a[3];   
    if(a[2]%2==1)
        a[1]-=2;
    if(a[1]>0)
        ans+=ceil((double)a[1]/4); 
       
    
    cout<<ans;

    return 0;
}