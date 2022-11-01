#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> a(n+1,0);
    vector<long long> v(n+1,0);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        v[i]=v[i-1]+a[i];
    }
    map<long long,vector<int>> m;
    for(int i=n;i>=0;i--) m[v[i]].push_back(i);
    multiset<int> s;
    s.insert(n+1);
    for(auto [val,x]:m) if(x.size()>=2) s.insert(x[x.size()-2]);
    long long res=0;
    for(int i=0;i<=n;i++)
    {
        res+=(*s.begin()-i-1);
        m[v[i]].pop_back();
        if(!m[v[i]].empty()) s.erase(s.find(m[v[i]].back()));
        if(m[v[i]].size()>=2) s.insert(m[v[i]][m[v[i]].size()-2]);
    }
    printf("%I64d\n",res);
    return 0;
}