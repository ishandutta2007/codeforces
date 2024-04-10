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
        vector<int> cnt(26,0);
        for(int i=0;i<n;i++)
        {
            cnt[s[i]-'a']++;
            cnt[t[i]-'a']++;
        }
        bool ok=1;
        for(int i=0;i<26;i++) if(cnt[i]&1) ok=0;
        if(ok==0)
        {
            printf("No\n");
            continue;
        }
        printf("Yes\n");
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            if(s[i]==t[i]) continue;
            int idx=-1;
            for(int j=i+1;j<n;j++) if(s[j]==s[i]) idx=j;
            if(idx!=-1)
            {
                v.push_back({idx,i});
                swap(s[idx],t[i]);
            }
            else
            {
                for(int j=i+1;j<n;j++) if(t[j]==s[i]) idx=j;
                v.push_back({n-1,idx});
                swap(s[n-1],t[idx]);
                v.push_back({n-1,i});
                swap(s[n-1],t[i]);
            }
        }
        printf("%d\n",(int)v.size());
        for(pair<int,int> p:v) printf("%d %d\n",p.first+1,p.second+1);
    }
    return 0;
}