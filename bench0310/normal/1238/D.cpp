#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    char s[n+1];
    scanf("%s",s);
    vector<int> v;
    int cnt=1;
    for(int i=1;i<n;i++)
    {
        if(s[i]==s[i-1]) cnt++;
        else
        {
            v.push_back(cnt);
            cnt=1;
        }
    }
    v.push_back(cnt);
    long long res=1ll*n*(n-1)/2;
    if(v.size()>1)
    {
        res-=v[0];
        res-=v.back();
        for(int i=1;i<(int)v.size()-1;i++) res-=2*v[i];
        res+=(v.size()-1);
    }
    printf("%I64d\n",res);
    return 0;
}