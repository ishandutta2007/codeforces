#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long long n,a[300*1000],i,j,last,ans;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(i=0;a[i]==a[0];i++);
    for(j=n-1,last=0;a[j]==a[n-1];j--,last++);
    if(a[0]==a[n-1])
        ans=(i*(i-1))/2;
    else
        ans=i*last;    
    cout<<a[n-1]-a[0]<<" "<<ans;
        
}