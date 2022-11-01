#include <bits/stdc++.h>

using namespace std;

int main()
{
    char s[300001];
    scanf("%s",s);
    int n=strlen(s);
    vector<pair<char,int>> v;
    int cnt=1;
    for(int i=1;i<=n;i++)
    {
        if(s[i]==s[i-1]) cnt++;
        else
        {
            v.push_back({s[i-1],cnt});
            cnt=1;
        }
    }
    bool res=(v.size()&1);
    int m=v.size()/2;
    if(v[m].second==1) res=0;
    int idx=0;
    while(m+idx<(int)v.size())
    {
        if(v[m-idx].first!=v[m+idx].first) res=0;
        if(v[m-idx].second+v[m+idx].second==2) res=0;
        idx++;
    }
    printf("%d\n",(v[m].second+1)*res);
    return 0;
}