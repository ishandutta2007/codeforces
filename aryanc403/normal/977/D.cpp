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
    LLI T,n,in,i,m,j;
    vector < pair < LLI , pair < LLI , LLI > > > a;
    vector <LLI> :: iterator it;

LLI p3(LLI n)
{
    LLI cnt=0;
    while(n%3==0)
    {
        n/=3;
        cnt++;
    }
    return cnt;
}

LLI p2(LLI n)
{
    LLI cnt=0;
    while(n%2==0)
    {
        n/=2;
        cnt++;
    }
    return cnt;
}

bool mysort(const pair < LLI , pair< LLI,LLI > > &c, const pair < LLI , pair<LLI,LLI> > &b)
{
    return (c.Y.X>b.Y.X)|| (c.Y.X==b.Y.X&&c.Y.Y<b.Y.Y);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //scanf(" %lld",&T);
    //while(T--)
    {
        scanf(" %lld",&n);
        a.clear();
        a.reserve(n);
        
        fo(i,n)
        {
            scanf(" %lld",&in);
            a.pb(mp(in,mp(p3(in),p2(in))));
        }
        
        sort(a.begin(),a.end(),mysort);
        
        fo(i,n)
            printf("%lld ",a[i].X);
    }
    return 0;
}