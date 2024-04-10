#include"bits/stdc++.h"
using namespace std;
#define ll long long
int ans[300005];
int l[300005],r[300005];
char s[300005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        scanf("%s",s);
        int last=0;
        for(int i=1;i<n;i+=2)
        {
            if(s[i]=='R')s[i]='L';
            else s[i]='R';
        }
        last=0;
        for(int i=0;i<=n;i+=2)
        {
            last=i;
            while(s[last]=='R')last++;
            for(int j=i;j<=last;j+=2)
            {
                r[j]=last-j;
                i=j;
            }
        }
        for(int i=1;i<=n;i+=2)
        {
            last=i;
            while(s[last]=='L')last++;
            for(int j=i;j<=last;j+=2)
            {
                r[j]=last-j;
                i=j;
            }
        }
        if(n%2==0)for(int i=0;i<n;i++)if(s[i]=='L')s[i]='R';else s[i]='L';
        for(int i=n;i>=0;i-=2)
        {
            last=i;
            while(last>=0&&s[last-1]=='L')last--;
            for(int j=i;j>=last;j-=2)
            {//if(j==1)cout<<last<<endl;
                l[j]=j-last;
                i=j;
            }
        }//cout<<"ok"<<endl;
        for(int i=n-1;i>=0;i-=2)
        {
            last=i;
            while(last>=0&&s[last-1]=='R')last--;
            for(int j=i;j>=last;j-=2)
            {
                l[j]=j-last;
                i=j;
            }
        }/*
        for(int i=0;i<=n;i++)
        {
            printf("%d%c",l[i]," \n"[i==n]);
        }
        for(int i=0;i<=n;i++)
        {
            printf("%d%c",r[i]," \n"[i==n]);
        }*/
        for(int i=0;i<=n;i++)
        {
            printf("%d%c",l[i]+r[i]+1," \n"[i==n]);
        }
    }
    return 0;
}