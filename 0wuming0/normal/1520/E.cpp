#include"bits/stdc++.h"
using namespace std;
char s[1400035];
#define ll long long
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        scanf("%s",s);int num=0;
        for(int i=0;s[i];i++)
        {
            if(s[i]=='*')num++;
        }
        num=num/2+1;
        int num2=0;int i;
        for(i=0;s[i];i++)
        {
            if(s[i]=='*')
            {
                num2++;if(num2==num)break;
            }
        }
        int v=i-1;
        long long ans=0;
        for(int j=0;j<i;j++)if(s[j]=='*')
        {
            ans+=v-j;
            v--;
        }
        v=i+1;
        for(int j=i+1;j<n;j++)if(s[j]=='*')
        {
            ans-=v-j;
            v++;
        }
        cout<<ans<<endl;
    }
    return 0;
}