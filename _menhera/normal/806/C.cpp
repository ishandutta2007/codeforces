#include<bits/stdc++.h>
using namespace std;

map<long long, int> cnt;
int N;
vector<vector<long long> > haystack;
set<int> ctlast[50];
bool push(long long x)
{
    int lg2 = 0;
    while(x!=1)
    {
        x/=2; ++lg2;
    }
    for(int i=lg2; i<45; ++i)
    {
        if(ctlast[i].size()!=0)
        {
            int v = *ctlast[i].begin();
            ctlast[i].erase(v);
            haystack[v].push_back(x);
            return true;
        }    
    }
    return false;
}
bool resolve(vector<long long> V)
{
    for(auto x: V)
        if(!push(x)) return false;
    return true;
}
int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; ++i)
    {
        long long int T;
        scanf("%lld", &T);
        cnt[T] = cnt[T] + 1;
    }
    while(cnt[1] != 0)
    {
        vector<long long> V;
        V.push_back(1);
        cnt[1] = cnt[1] - 1;
        int x = 0;
        long long no = 2;
        while(cnt[no] != 0)
        {
            x ++;
            cnt[no] = cnt[no] - 1;
            V.push_back(no);
            no *= 2;
        }
        haystack.push_back(V);
        ctlast[x].insert(haystack.size()-1);
    }
    vector<long long> nokori;
    for(auto x: cnt)
        for(int i=0; i<x.second; ++i) nokori.push_back(x.first);
    int ansst = haystack.size();
    int ansnd = haystack.size();
    if(!resolve(nokori))
    {
        puts("-1");
        return 0;
    }
    while(true)
    {
        vector<long long> v = haystack[haystack.size()-1];
        haystack.pop_back();
        if(v.size()==1 || v[v.size()-2]*2 == v[v.size()-1])
            ctlast[v.size()-1].erase(haystack.size());
        if(!resolve(v))
        {
            for(int i=ansnd; i<=ansst; ++i)
                printf("%d ",i);
            puts("");
            return 0;
        }
        ansnd--;
    }
    return 0;
    
}