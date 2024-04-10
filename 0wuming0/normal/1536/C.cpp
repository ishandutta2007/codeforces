#include"bits/stdc++.h"
using namespace std;
char s[500005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        scanf("%s",s);
        map<pair<int,int>,int>mp;
        pair<int,int>pr;
        int a=0,b=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='K')a++;
            else b++;
            int g=__gcd(a,b);
            pr.first=a/g;
            pr.second=b/g;
            if(mp.find(pr)!=mp.end())mp[pr]++;
            else mp[pr]=1;
            printf("%d%c",(mp.find(pr))->second," \n"[i==n-1]);
        }
    }
    return 0;
}