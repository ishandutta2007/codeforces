#include<iostream>
#include<vector>
using namespace std;

int main()
{
    long long k, ans=0;

    scanf("%lld",&k);

    char a[1000005];
    scanf("%s",a);

    vector<long long> len;
    long long cnt=0;

    for(int i=0;a[i];++i)
    {
        if(a[i]=='1')
        {
            len.push_back(cnt+1);
            cnt=0;
        }
        else
            ++cnt;
    }
    len.push_back(1+cnt);
    int n=len.size();
    long long sum=0;

    for(int i=0;i<n;++i)
    {
        ans+=len[i]*((i+k<n?len[i+k]:0ll));
        sum+=len[i]*(len[i]-1)/2;
    }
    if(!k)
        ans=sum;
    printf("%lld",ans);
}