#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n,k,a[2200],ans=0;
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
     sort(a,a+n);
     for(int i=n-1;i>=0;i-=k)
         ans+=(a[i]-1)*2;
    cout<<ans<<endl;       

    return 0;
}