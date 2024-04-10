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
    LLI T,n,in,i,m,j,k,w;
    vector <LLI> a;
    vector <LLI> :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //scanf(" %lld",&T);
    LLI ma=0;//while(T--)
        scanf(" %lld %lld",&n,&w);
    LLI mi=w+1;
    LLI sum=0;    
        fo(i,n)
        {
            scanf(" %lld",&in);
            sum+=in;
            mi=min(mi,sum);
            ma=max(ma,sum);
        }
    if(w>=ma-mi&&ma<=w&&mi>=-w&&ma>=mi)
    {
        LLI cnt=w+1;
        if(mi<0)
        {
            cnt+=mi;
        }
        if(ma>0)
        {
            cnt-=ma;
        }
        cout<<cnt;
    }
    else
    {
        printf("0");
    }
    return 0;
}