#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        char s[n+1],t[n+1];
        scanf("%s%s",s,t);
        vector<int> v;
        for(int i=0;i<n;i++) if(s[i]!=t[i]) v.push_back(i);
        if(v.empty()) printf("Yes\n");
        else if(v.size()!=2) printf("No\n");
        else if(s[v[0]]==s[v[1]]&&t[v[0]]==t[v[1]]) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}