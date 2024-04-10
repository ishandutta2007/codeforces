#include<bits/stdc++.h>
using namespace std;
int N; long long T;
pair<int, long long > at[201010];
vector<int> ans;
bool can(int x, bool print = false)
{
    vector<pair<long long, int > > gather;
    for(int i=0; i<N; ++i)
        if(x<=at[i].first)
            gather.emplace_back(at[i].second, i);
    sort(gather.begin(), gather.end());
    if(gather.size() < x) return false;
    long long myT = 0; 
    for(int i=0; i<x; ++i)
    {
        myT += gather[i].first;
        if(print) ans.push_back(gather[i].second);
    }
    return myT <= T;
}
int main()
{
    scanf("%d%lld", &N, &T);
    for(int i=0; i<N; ++i)
        scanf("%d%lld", &at[i].first, &at[i].second);
    int lo = 0; // yes 
    int hi = N+1; // no
    while(lo+1!=hi)
    {
        int mi = (lo+hi)/2;
        if(can(mi)) lo = mi;
        else hi = mi;
    }
    can(lo, true);
    printf("%d\n%d\n", lo, lo);
    for(auto x: ans)
        printf("%d ", x+1);
    puts("");
    return 0;
}