#include"bits/stdc++.h"
using namespace std;
char s[1005];
int a[1005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        scanf("%s",s+1);
        map<int,int>mp;
        mp[0]=1;
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='a')
            {
                a[i]=a[i-1]+1;
            }
            else a[i]=a[i-1]-1;
            if(mp.find(a[i])!=mp.end())
            {
                printf("%d %d\n",mp[a[i]],i);
                goto ne;
            }
            else
            {
                mp[a[i]]=i+1;
            }
        }
        printf("-1 -1\n");
        ne:;
    }
    return 0;
}