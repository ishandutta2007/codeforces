#include"bits/stdc++.h"
using namespace std;
#define ll long long
char s[200005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%s",s);
        int t1=0,t2=0;
        int ans=0;
        for(int i=0;s[i];i++)
        {
            if(s[i]=='(')t1++;
            if(s[i]==')'&&t1>0)t1--,ans++;
            if(s[i]=='[')t2++;
            if(s[i]==']'&&t2>0)t2--,ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}