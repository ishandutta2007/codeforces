#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define lli long long int
#define fo(i,n) for(i=0;i<(n);i++)
string npos;
long long int min(long long int a,long long int b)
{
    return a<b?a:b;
}
long long int max(long long a,long long b)
{
    return a>b?a:b;
}
long long int i,j;
int main() {
    int n,k;
    cin>>n>>k;
    long double a[n];
    fo(i,n)
    cin>>a[i];
    long double max=0;
    for(i=k;i<n+1;i++)
    {
        long double sum=0; 
        for(j=0;j<i;j++)
        {
            sum+=a[j];
        }
        if(sum>max*i)
        max=sum/i;
        for(j=1;j<n-i+1;j++)
        {
            sum-=a[j-1];
            sum+=a[j+i-1];
            if(sum>max*i)
            max=sum/i;
        }
    }
    printf("%.16Lf\n",max);
    return 0;
}