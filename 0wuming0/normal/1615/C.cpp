#include"bits/stdc++.h"
using namespace std;
char s[200005],s2[200005];
int ok[200005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        scanf("%s%s",s,s2);
        int num00=0,num01=0,num11=0,num10=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0'&&s2[i]=='0')num00++;
            if(s[i]=='1'&&s2[i]=='0')num10++;
            if(s[i]=='1'&&s2[i]=='1')num11++;
            if(s[i]=='0'&&s2[i]=='1')num01++;
        }
        int ans1=1e9,ans2=1e9;
        if(num10-num01==0||num10-num01==1)
        {
            if((num10+num01)%2==0)ans1=num10+num01;
        }
        if(num11-num00==0||num11-num00==1)
        {
            if((num11-num00)%2==1)ans2=num11+num00;
        }
        ans1=min(ans1,ans2);
        if(ans1==1e9)ans1=-1;
        printf("%d\n",ans1);
    }
    return 0;
}