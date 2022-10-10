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
#define MAX 100002
#define MOD 1000000007

/*#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
#ifdef LOCAL_TEST
    freopen("in.txt","r",stdin);
#endif*/

    LLI T,n,in,i,m,j,k,u;
    vector <LLI> a;
    vector <LLI> :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    scanf(" %lld %lld",&n,&u);
    double m=-1;
    bool t=false;
    a.clear();
    a.reserve(n);
    fo(i,n)
    {
        scanf(" %lld",&in);
        a.pb(in);
    }
    
    i=0;
    k=2;
    
    while(k<n&&i+2<n)
    {
        while(k<n&&a[k]-a[i]<=u)
        {
            k++;
        }
        
        k--;
        if(k<n&&k>=i+2&&a[k]-a[i]<=u)
        {
            t=true;
            //printf("%lldi %lldk\n",i,k);
            m=max(m,(a[k]-a[i+1])/(double)(a[k]-a[i]));
        }
        i++;
    }
    
    if(t)
        printf("%.10lf\n",m);
    else
        printf("-1");
    return 0;
}