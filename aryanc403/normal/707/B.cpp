//for(auto a: x);
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include<stdio.h>
#define fo(i,n)   for(i=0;i<(n);++i)
#define LLI long long int
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define MAX 1000002
#define MOD 1000000007
    LLI T,n,in,i,m,j,k,x,y,l,sz[100005];
    vector < pair<LLI,LLI> > ed[100005];
    vector < pair<LLI,LLI> > :: iterator it;
    vector <LLI> a;

bool cmp(const pair<LLI,LLI> &a,const pair<LLI,LLI> &b)
{
    return a.Y<b.Y;
}

bool bs(vector <LLI> &a, LLI n,LLI x)
{
    LLI l,m,r;
    l=0;
    r=n-1;
    while(l<=r)
    {
        m=l+(r-l)/2;
        if(a[m]==x)
        {
            return true;
        }
        else if(a[m]<x)
        {
            l=m+1;
        }
        else
        {
            r=m-1;
        }
    }
    return false;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>k;
        a.clear();
        a.reserve(n);
        
        fo(i,m)
        {
            cin>>x>>y>>l;
            ed[x].pb(mp(y,l));
            ed[y].pb(mp(x,l));
            sz[x]++;
            sz[y]++;
        }
        
        fo(i,k)
        {
            cin>>x;
            a.pb(x);
        }
        for(i=1;i<=n;++i)
        {
            sort(ed[i].begin(),ed[i].end(),cmp);
        }
    LLI ans=MOD;
    sort(a.begin(),a.end());
    fo(i,k)
    {
        for(j=0;j<sz[a[i]];++j)
        {
            if(bs(a,k,ed[a[i]][j].X)==false)
            {
                ans=min(ans,ed[a[i]][j].Y);
                break;
            }
        }
    }
    cout<<(ans==MOD?-1:ans);
    return 0;
}