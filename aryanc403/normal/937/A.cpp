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
    vector <LLI> a;
    vector <LLI> :: iterator it;

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
            a.pb(in);
        }
        
        sort(a.begin(),a.end());
        in=0;
        a.pb(in);
        for(i=0;i<n;++i)
        {
            if(a[i]!=a[i+1]&&a[i])
            {
                in++;
            }
        }
        
        printf("%lld\n",in);
        
    }
    return 0;
}