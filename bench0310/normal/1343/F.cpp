#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool ch(int n,vector<int> p,vector<set<int>> &v)
{
    if(n!=(int)p.size()) return 0;
    reverse(p.begin(),p.end());
    vector<bool> vis(n-1,0);
    for(int o=1;o<n;o++)
    {
        set<int> s;
        bool b=0;
        for(int i=o;i>=0;i--)
        {
            s.insert(p[i]);
            for(int j=0;j<n-1;j++)
            {
                if(vis[j]==1) continue;
                if(s==v[j])
                {
                    vis[j]=1;
                    b=1;
                    break;
                }
            }
            if(b==1) break;
        }
    }
    bool ok=1;
    for(int i=0;i<n-1;i++) if(vis[i]==0) ok=0;
    return ok;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        vector<set<int>> v(n-1);
        vector<int> c(n+1,0);
        for(int i=0;i<n-1;i++)
        {
            int k;
            scanf("%d",&k);
            set<int> s;
            for(int j=0;j<k;j++)
            {
                int x;
                scanf("%d",&x);
                s.insert(x);
                c[x]++;
            }
            v[i]=s;
        }
        function<vector<int>(vector<int>,vector<bool>,vector<int>,int)> solve_end=[&](vector<int> p,vector<bool> vis,vector<int> cnt,int a)->vector<int>
        {
            if((int)p.size()==n-1)
            {
                vector<bool> used(n+1,0);
                for(int x:p) used[x]=1;
                int idx=0;
                for(int i=1;i<=n;i++) if(used[i]==0) idx=i;
                p.push_back(idx);
                return p;
            }
            vector<int> one;
            for(int i=1;i<=n;i++) if(cnt[i]==1&&i!=a) one.push_back(i);
            if(one.size()!=1) return p;
            for(int o=0;o<n-1;o++)
            {
                if(vis[o]) continue;
                if(v[o].find(one[0])!=v[o].end())
                {
                    vis[o]=1;
                    for(int x:v[o]) cnt[x]--;
                    break;
                }
            }
            p.push_back(one[0]);
            return solve_end(p,vis,cnt,a);
        };
        function<vector<int>(vector<int>,vector<bool>,vector<int>)> solve_unique=[&](vector<int> p,vector<bool> vis,vector<int> cnt)->vector<int>
        {
            if((int)p.size()==n-1)
            {
                vector<bool> used(n+1,0);
                for(int x:p) used[x]=1;
                int idx=0;
                for(int i=1;i<=n;i++) if(used[i]==0) idx=i;
                p.push_back(idx);
                return p;
            }
            vector<int> one;
            for(int i=1;i<=n;i++) if(cnt[i]==1) one.push_back(i);
            if(one.size()==1)
            {
                for(int o=0;o<n-1;o++)
                {
                    if(vis[o]) continue;
                    if(v[o].find(one[0])!=v[o].end())
                    {
                        vis[o]=1;
                        for(int x:v[o]) cnt[x]--;
                        break;
                    }
                }
                p.push_back(one[0]);
                return solve_unique(p,vis,cnt);
            }
            else
            {
                vector<int> cp=p;
                vector<bool> cvis=vis;
                vector<int> ccnt=cnt;
                for(int o=0;o<n-1;o++)
                {
                    if(vis[o]) continue;
                    if(v[o].find(one[0])!=v[o].end())
                    {
                        vis[o]=1;
                        for(int x:v[o]) cnt[x]--;
                        break;
                    }
                }
                p.push_back(one[0]);
                vector<int> z=solve_end(p,vis,cnt,one[1]);
                if(ch(n,z,v)==1) return z;
                cp.push_back(one[1]);
                for(int o=0;o<n-1;o++)
                {
                    if(cvis[o]) continue;
                    if(v[o].find(one[1])!=v[o].end())
                    {
                        cvis[o]=1;
                        for(int x:v[o]) ccnt[x]--;
                        break;
                    }
                }
                return solve_end(cp,cvis,ccnt,one[0]);
            }
        };
        vector<int> p=solve_unique({},vector<bool>(n-1,0),c);
        reverse(p.begin(),p.end());
        for(int i=0;i<n;i++) printf("%d%c",p[i]," \n"[i==n-1]);
    }
    return 0;
}