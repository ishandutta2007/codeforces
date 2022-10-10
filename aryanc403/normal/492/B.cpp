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
    LLI T,n,in,i,m,j,L;
    vector <LLI> a;
    vector <LLI> :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    scanf(" %lld %lld",&n,&L);
    a.clear();
    a.reserve(n);
        
        fo(i,n)
        {
            scanf(" %lld",&in);
            a.pb(in);
        }
        sort(a.begin(),a.end());
    double l,r,mid,d,cov;
    const double e = 0.0000000001; 
    l=0;
    r=L;
    while(l+e<r)
    {
        d=l+(r-l)/2;
        cov=0;
        bool all=true;
        fo(i,n)
        {
            if(cov<a[i]-d)
            {
                all=false;
                break;
            }
            cov=max(cov,a[i]+d);
        }
        
        if(all&&cov>=L)
        {
            r=d;
        }
        else
        {
            l=d;
        }
    }
    printf("%.10f",l);//cout<<l;
    return 0;
}