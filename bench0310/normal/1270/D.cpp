#include <bits/stdc++.h>

using namespace std;

pair<int,int> query(vector<int> v)
{
    printf("?");
    for(int a:v) printf(" %d",a);
    printf("\n");
    fflush(stdout);
    pair<int,int> p;
    scanf("%d%d",&p.first,&p.second);
    return p;
}

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    vector<int> v(n+1,-1);
    for(int i=0;i<n-k+1;i++)
    {
        vector<int> now;
        for(int j=1;j<=n&&(int)now.size()<k;j++) if(v[j]==-1) now.push_back(j);
        pair<int,int> p=query(now);
        v[p.first]=p.second;
    }
    vector<int> unknown;
    for(int i=1;i<=n;i++) if(v[i]==-1) unknown.push_back(i);
    vector<pair<int,int>> two;
    for(int i=1;i<=n&&(int)two.size()<2;i++) if(v[i]!=-1) two.push_back({i,v[i]});
    if(two[0].second>two[1].second) swap(two[0],two[1]);
    int s=k-1;
    for(int i=0;i<k-1;i++)
    {
        vector<int> now;
        now.push_back(two[0].first);
        now.push_back(two[1].first);
        for(int j=0;j<k-1;j++) if(i!=j) now.push_back(unknown[j]);
        if(query(now).first==two[0].first) s--;
    }
    printf("! %d\n",s+1);
    fflush(stdout);
    return 0;
}