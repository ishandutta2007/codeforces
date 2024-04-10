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
    LLI T,n,in,i,m,j,k;
    vector <LLI> ed[30003];
    bool vis[30003];
    vector <LLI> :: iterator it;

void dfs(LLI x)
{
    if(x>T||vis[x])
    {
        return;
    }
    vis[x]=true;
    dfs(ed[x][0]);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>T;
    for(i=1;i<=T;++i)
    {
        cin>>in;
        ed[i].pb(in+i);
    }
    dfs(1);
    cout<<(vis[T]?"YES":"NO");
    return 0;
}