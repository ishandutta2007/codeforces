#include"bits/stdc++.h"
using namespace std;
int Main();
int t=Main();
int main(){};
int Main()
{
    int n;
    cin>>n;
    int a[200004];
    for(int i=0;i<n;i++)scanf("%d",a+i);
    sort(a,a+n);
    long long ans;
    if(a[0]==a[n-1])ans=n*(long long)(n-1)/2;
    else
    {
        int i,j,k=1;
        for(i=1;i<n;i++)if(a[i]!=a[i-1])break;
        for(j=n-2;j>=0;j--)if(a[j]!=a[j+1])break;else k++;
        ans=i;
        ans=ans*k;
    }
    cout<<a[n-1]-a[0]<<" "<<ans<<endl;
    return 0;
}