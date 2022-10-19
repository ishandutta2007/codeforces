#include"bits/stdc++.h"
using namespace std;
int gcd(int a,int b)
{
    if(a==0||b==0)return a+b;
    return gcd(b,a%b);
}
int ans[2000005];
int main()
{
    int t;
    int a,b;
    cin>>t>>a>>b;
    int g=gcd(a,b);
    a/=g;
    b/=g;
    long long last1=b,last2=a;
    for(int i=1;i<a+b-1;i++)
    {
        if(last1<last2)
        {
            ans[i]=1;
            last1+=b;
        }
        else
        {
            ans[i]=0;
            last2+=a;
        }
    }
    long long last=0;
    while(t--)
    {
        long long n;
        scanf("%lld",&n);
        //last+=n;
        //n=last;
        n%=(a+b);
        if(n==0||n==a+b-1)printf("Both\n");
        else if(ans[n])printf("Vanya\n");
        else printf("Vova\n");
    }
    return 0;
}