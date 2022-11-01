#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    map<pair<int,int>,vector<int>> m;
    vector<int> cnt(n+1,0);
    vector<pair<int,int>> v(n+1);
    for(int o=0;o<n-2;o++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        cnt[a]++;
        cnt[b]++;
        cnt[c]++;
        v[a]={b,c};
        v[b]={a,c};
        v[c]={a,b};
        m[{a,b}].push_back(c);
        m[{b,a}].push_back(c);
        m[{a,c}].push_back(b);
        m[{c,a}].push_back(b);
        m[{b,c}].push_back(a);
        m[{c,b}].push_back(a);
    }
    int idx=0;
    for(int i=1;i<=n;i++) if(cnt[i]==1) idx=i;
    vector<bool> used(n+1,0);
    used[idx]=1;
    vector<int> res;
    res.reserve(n);
    res.push_back(idx);
    if(cnt[v[idx].first]==2) res.push_back(v[idx].first);
    else res.push_back(v[idx].second);
    used[res.back()]=1;
    while((int)res.size()<n)
    {
        int a=res[res.size()-2];
        int b=res.back();
        if(used[m[{a,b}][0]]) res.push_back(m[{a,b}][1]);
        else res.push_back(m[{a,b}][0]);
        used[res.back()]=1;
    }
    for(int i=0;i<n;i++) printf("%d%c",res[i]," \n"[i==n-1]);
    return 0;
}