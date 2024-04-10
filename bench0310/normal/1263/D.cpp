#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    bool a[26][26];
    for(int i=0;i<26;i++) for(int j=0;j<26;j++) a[i][j]=0;
    char s[51];
    for(int o=0;o<n;o++)
    {
        scanf("%s",s);
        int m=strlen(s);
        vector<bool> t(26,0);
        for(int i=0;i<m;i++) t[s[i]-'a']=1;
        for(int i=0;i<26;i++) for(int j=0;j<26;j++) if(t[i]&&t[j]) a[i][j]=1;
    }
    vector<bool> vis(26,0);
    int res=0;
    for(int i=0;i<26;i++)
    {
        if(a[i][i]==0||vis[i]==1) continue;
        res++;
        queue<int> q;
        q.push(i);
        vis[i]=1;
        while(!q.empty())
        {
            int e=q.front();
            q.pop();
            for(int j=0;j<26;j++)
            {
                if(a[e][j]==1&&vis[j]==0)
                {
                    q.push(j);
                    vis[j]=1;
                }
            }
        }
    }
    printf("%d\n",res);
    return 0;
}