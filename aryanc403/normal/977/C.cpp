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
    vector <LLI> a;
    vector <LLI> :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    scanf(" %lld",&n);
    //while(T--)
    {
        scanf(" %lld",&k);
        a.clear();
        a.reserve(n);
        
        fo(i,n)
        {
            scanf(" %lld",&in);
            a.pb(in);
        }
        sort(a.begin(),a.end());
    }
    if(k>0)
    {
    if(a[k-1]==a[k])
    {
        in=-1;
    }
    else
        in=a[k-1];
    }
    else if(a[0]==1)
    {
        in=-1;
    }
    else
    {
        in=1;
    }
    
    printf("%lld",in);
    return 0;
}