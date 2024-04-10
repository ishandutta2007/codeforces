#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,a,b;
        cin>>n>>a>>b;
        char s[200003];
        scanf("%s",s);
        ll len=strlen(s);
        ll i,j,k;
        ll ans=a*len+b*(len+1);
        ll a1=0,a2=0,a3=0;
        for(j=0;j<len;j++)
        {
            if(s[j]=='1')break;
        }
        if(j==len)
        {
            printf("%lld\n",ans);
            continue;
        }
        ans+=a;//cout<<"!"<<ans<<endl;
        for(k=len-1;;k--)
        {
            if(s[k]=='1')break;
        }
        ans+=a;
        for(;j<=k;j++)
        {
            if(s[j]=='1')ans+=b;
            else
            {
                ans+=b;
                a1=0;
                while(s[j]=='0')j++,a1++;
                j--;
                ans+=min(2*a,(a1-1)*b);
            }
        }
        printf("%lld\n",ans+b);
    }
    return 0;
}
/*
2
2 10 10
11
*/