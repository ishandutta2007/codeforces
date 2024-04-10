#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    char z[200001];
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        scanf("%s",z);
        vector<bool> vis(n,0);
        int res=0;
        for(int o=0;o<k;o++)
        {
            if(vis[o]) continue;
            set<int> s;
            for(int i=o;i<n;i+=k) s.insert(i);
            for(int i=n-1-o;i>=0;i-=k) s.insert(i);
            for(int x:s) vis[x]=1;
            vector<int> v(26,0);
            for(int x:s) v[z[x]-'a']++;
            int m=0;
            for(int i=0;i<26;i++) m=max(m,v[i]);
            res+=(s.size()-m);
        }
        printf("%d\n",res);
    }
    return 0;
}