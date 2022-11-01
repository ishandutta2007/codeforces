#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
long long n,k,a[200*1000],dp[200*1000],sum,ans,index[200*1000],allsum[200*1000];

int main()
{ 
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    allsum[0]=a[0]; 
    for(int i=1;i<n;i++)
        allsum[i]=allsum[i-1]+a[i];
    for(int i=n-1;i>n-k-1;i--)  
        dp[n-k]+=a[i];
    index[n-k]=n-k; 
    for(int i=n-k-1;i>=0;i--)
    {
        if(dp[i+1]>allsum[i+k-1]-allsum[i-1])
        {
            dp[i]=dp[i+1];
            index[i]=index[i+1];
        }
        else
        {
            dp[i]=allsum[i+k-1]-allsum[i-1];
            index[i]=i;
        }
        
    }   
    for(int i=0;i<k;i++)
        sum+=a[i];
    ans=sum+dp[k];  
    long long index2=0;
    for(int i=k;i<n;i++)
    {
        sum+=a[i]-a[i-k];
        if(ans<sum+dp[i+1])
        {
            ans=sum+dp[i+1];
            index2=i-k+1;
        }
    }   
    cout<<index2+1<<" "<<index[index2+k]+1;
    return 0;
}