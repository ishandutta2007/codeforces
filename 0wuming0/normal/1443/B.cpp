#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;char s[100005];
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        scanf("%s",s);
        char *p=s;
        while(*p=='0')p++;
        int ans=0;
        if(*p)
        while(1)
        {
            int num=0;
            while(*p=='1')p++;
            while(*p=='0')p++,num++;
            if(*p==0)
            {
                ans+=a;
                break;
            }
            else ans+=min(num*b,a);
        }
        cout<<ans<<endl;
    }
    return 0;
}