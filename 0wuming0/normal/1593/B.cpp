#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n;
        scanf("%lld",&n);
        long long s;
        int now,ans=120,op;
        s=n;op=0;now=0;
        for(;s;s/=10)
        {
            if(op==0&&s%10==0)op++;
            else if(op==1&&(s%10==0||s%10==5))op++;
            now++;
            if(op==2)
            {
                ans=min(ans,now-2);
                break;
            }
        }
        s=n;op=0;now=0;
        for(;s;s/=10)
        {
            if(op==0&&s%10==5)op++;
            else if(op==1&&(s%10==2||s%10==7))op++;
            now++;
            if(op==2)
            {
                ans=min(ans,now-2);
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}