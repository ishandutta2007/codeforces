#include"bits/stdc++.h"
using namespace std;
int odd[1000006],even[1000006];
char s[1000006];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%s",s+1);
        int n=strlen(s+1);
        for(int i=1;i<=n;i++)
        {
            if(s[i]==')')s[i]='(';
            if(s[i]==']')s[i]='[';
        }
        for(int i=1;i<n;i+=2)
        {
            if(s[i]==s[i+1])odd[i]=0;
            else if(s[i]=='(')odd[i]=1;
            else odd[i]=-1;
        }
        for(int i=2;i<n;i+=2)
        {
            if(s[i]==s[i+1])even[i]=0;
            else if(s[i]=='(')even[i]=1;
            else even[i]=-1;
        }
        for(int i=1;i<n;i+=2)odd[i]+=odd[i-2];
        for(int i=2;i<n;i+=2)even[i]+=even[i-2];
        int q;
        cin>>q;
        while(q--)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            r--;
            if(l&1)printf("%d\n",abs(odd[r]-odd[l-2]));
            else printf("%d\n",abs(even[r]-even[l-2]));
        }
        for(int i=0;i<=n;i++)odd[i]=even[i]=0;
    }
    return 0;
}