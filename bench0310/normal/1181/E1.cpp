#include <bits/stdc++.h>

using namespace std;

bool solvex(int l,int r);
bool solvey(int l,int r);
struct obj
{
    int a,b,c,d;
};

int n;
obj v[1000];
set<pair<int,int>> s;

bool solvex(int l,int r)
{
    if(s.find({l,r})!=s.end()) return 0;
    s.insert({l,r});
    if(l+1==r) return 1;
    sort(v+l,v+r,[](obj a,obj b){return a.a<b.a;});
    int now=v[l].c;
    int idx=l;
    bool res=1;
    int t=l;
    while(idx<r)
    {
        while(idx<r&&v[idx].a<now)
        {
            now=max(now,v[idx].c);
            idx++;
        }
        if(solvey(t,idx)==0) res=0;
        t=idx;
        now=v[idx].c;
    }
    return res;
}

bool solvey(int l,int r)
{
    if(l+1==r) return 1;
    sort(v+l,v+r,[](obj a,obj b){return a.b<b.b;});
    int now=v[l].d;
    int idx=l;
    bool res=1;
    int t=l;
    while(idx<r)
    {
        while(idx<r&&v[idx].b<now)
        {
            now=max(now,v[idx].d);
            idx++;
        }
        if(solvex(t,idx)==0) res=0;
        t=idx;
        now=v[idx].d;
    }
    return res;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d%d%d%d",&v[i].a,&v[i].b,&v[i].c,&v[i].d);
    if(solvex(0,n)) printf("YES\n");
    else printf("NO\n");
    return 0;
}