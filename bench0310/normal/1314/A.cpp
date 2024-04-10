#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++) scanf("%d",&v[i].first);
    for(int i=0;i<n;i++) scanf("%d",&v[i].second);
    sort(v.begin(),v.end());
    int now=0;
    long long sum=0;
    long long res=0;
    multiset<int> s;
    int idx=0;
    while(idx<n||!s.empty())
    {
        if(s.empty()) now=(*lower_bound(v.begin(),v.end(),make_pair(now,0))).first;
        while(idx<n&&v[idx].first==now)
        {
            sum+=v[idx].second;
            s.insert(v[idx].second);
            idx++;
        }
        sum-=(*s.rbegin());
        s.erase(prev(s.end()));
        res+=sum;
        now++;
    }
    printf("%I64d\n",res);
    return 0;
}