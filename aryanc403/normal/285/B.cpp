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
    LLI T,n,in,i,m,j,s,t;
    vector <LLI> a;
    vector <LLI> :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
        scanf(" %lld %lld %lld",&n,&s,&t);
        a.clear();
        a.reserve(n+1);
        a.pb(0);
        fo(i,n)
        {
            scanf(" %lld",&in);
            a.pb(in);
        }
    m=s;
    LLI cnt=0;
    
    if(s==t)
    {
        cout<<0;
        return 0;
    }
    
    cnt++;
    m=a[m];
    while(m!=t&&m!=s)
    {
        cnt++;
        m=a[m];
    }
    
    if(m!=s)
    {
        cout<<cnt;
    }
    else
    {
        cout<<-1;
    }
    
    return 0;
}