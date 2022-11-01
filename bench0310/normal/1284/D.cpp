#include <bits/stdc++.h>

using namespace std;

bool solve(vector<pair<int,int>> one,vector<pair<int,int>> two,int n)
{
    vector<array<int,3>> a; //pos,0/1,id
    vector<pair<int,int>> b; //l,r
    for(int i=0;i<n;i++)
    {
        int sa,ea,sb,eb;
        tie(sa,ea,sb,eb)=make_tuple(one[i].first,one[i].second,two[i].first,two[i].second);
        a.push_back({sa,0,i});
        a.push_back({ea,1,i});
        b.push_back({sb,eb});
    }
    sort(a.begin(),a.end());
    set<pair<int,int>> l,r;
    bool bad=0;
    for(int i=0;i<2*n;i++)
    {
        if(a[i][1]==0)
        {
            int id=a[i][2];
            l.insert({b[id].first,id});
            r.insert({b[id].second,id});
            if(((*r.begin()).first)<((*l.rbegin()).first)) bad=1;
        }
        else
        {
            int id=a[i][2];
            l.erase({b[id].first,id});
            r.erase({b[id].second,id});
        }
    }
    return bad;
}

int main()
{
    int n;
    scanf("%d",&n);
    vector<pair<int,int>> one(n),two(n);
    for(int i=0;i<n;i++) scanf("%d%d%d%d",&one[i].first,&one[i].second,&two[i].first,&two[i].second);
    bool bad=0;
    bad=(bad|solve(one,two,n));
    bad=(bad|solve(two,one,n));
    if(bad==0) printf("YES\n");
    else printf("NO\n");
    return 0;
}