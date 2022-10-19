#include"bits/stdc++.h"
using namespace std;
char s[1005];
map<string,int>mp1,mp2,mp3;
int main()
{
    int t;
    cin>>t;
    char ss[30]={0};
    for(ss[0]='a';ss[0]<='z';ss[0]++)mp1[ss]=-2;
    for(ss[0]='a';ss[0]<='z';ss[0]++)
        for(ss[1]='a';ss[1]<='z';ss[1]++)mp2[ss]=-2;
    for(ss[0]='a';ss[0]<='z';ss[0]++)
        for(ss[1]='a';ss[1]<='z';ss[1]++)
            for(ss[2]='a';ss[2]<='z';ss[2]++)mp3[ss]=-2;
    while(t--)
    {
        int n;
        cin>>n;
        scanf("%s",s);
        ss[0]=ss[1]=ss[2]=0;
        for(int i=0;i<n;i++)
        {
            ss[0]=s[i];
            mp1[ss]=t;
        }
        for(int i=0;i<n-1;i++)
        {
            ss[0]=s[i];
            ss[1]=s[i+1];
            mp2[ss]=t;
        }
        for(int i=0;i<n-2;i++)
        {
            ss[0]=s[i];
            ss[1]=s[i+1];
            ss[2]=s[i+2];
            mp3[ss]=t;
        }
        for(auto pr:mp1)if(pr.second!=t)
        {
            cout<<pr.first<<endl;
            goto ed;
        }
        for(auto pr:mp2)if(pr.second!=t)
        {
            cout<<pr.first<<endl;
            goto ed;
        }
        for(auto pr:mp3)if(pr.second!=t)
        {
            cout<<pr.first<<endl;
            goto ed;
        }
        ed:;
    }
    return 0;
}