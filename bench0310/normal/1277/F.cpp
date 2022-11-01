#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    map<int,int> m;
    for(int i=0;i<n;i++)
    {
        int t;
        scanf("%d",&t);
        m[t]++;
    }
    vector<pair<int,int>> v;
    for(auto [a,b]:m) v.push_back({b,a});
    sort(v.begin(),v.end());
    int idx=0;
    int cnt=0;
    int best=0;
    int h=1;
    for(int i=1;i<=n;i++)
    {
        cnt+=(v.size()-idx);
        while(idx<(int)v.size()&&v[idx].first==i) idx++;
        int j=(cnt/i);
        if(j<i) continue;
        if(i*j>best)
        {
            best=i*j;
            h=i;
        }
    }
    reverse(v.begin(),v.end());
    vector<int> t;
    for(auto [a,b]:v)
    {
        for(int i=0;i<min(a,h);i++) t.push_back(b);
    }
    int w=(t.size()/h);
    while((int)t.size()>h*w) t.pop_back();
    vector<vector<int>> res(h,vector<int>(w,0));
    idx=0;
    for(int i=0;i<w;i++)
    {
        if(res[0][i]!=0) continue;
        int r=0,c=i;
        while(res[r][c]==0)
        {
            res[r][c]=t[idx++];
            r=(r+1)%h;
            c=(c+1)%w;
        }
    }
    printf("%d\n",h*w);
    printf("%d %d\n",h,w);
    for(int o=0;o<h;o++) for(int i=0;i<w;i++) printf("%d%c",res[o][i]," \n"[i==w-1]);
    return 0;
}