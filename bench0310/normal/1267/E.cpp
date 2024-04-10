#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int a[m][n];
    for(int o=0;o<m;o++) for(int i=0;i<n;i++) scanf("%d",&a[o][i]);
    vector<int> res;
    for(int i=0;i<m;i++) res.push_back(i);
    for(int o=0;o<n-1;o++)
    {
        int d=0;
        vector<pair<int,int>> t;
        for(int i=0;i<m;i++)
        {
            d+=(a[i][n-1]-a[i][o]);
            t.push_back({a[i][n-1]-a[i][o],i});
        }
        sort(t.begin(),t.end(),greater<pair<int,int>>());
        vector<int> v;
        for(int i=0;i<m;i++)
        {
            if(d<=0) break;
            d-=t[i].first;
            v.push_back(t[i].second);
        }
        if(v.size()<res.size()) res=v;
    }
    printf("%d\n",(int)res.size());
    for(int a:res) printf("%d ",a+1);
    printf("\n");
    return 0;
}