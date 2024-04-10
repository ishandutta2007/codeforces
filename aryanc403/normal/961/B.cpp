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

/*#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
#ifdef LOCAL_TEST
    freopen("in.txt","r",stdin);
#endif*/

    LLI T,n,in,i,m,j,k,a[100005],t;
    vector <LLI> :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    scanf(" %lld %lld",&n,&k);
    
    for(i=0;i<n;++i)
        scanf(" %lld",&a[i]);
    LLI sum=0,ns=0;
    for(i=0;i<n;++i)
    {
        scanf(" %lld",&t);
        if(t)
        {
            sum+=a[i];
            a[i]=ns;
        }
        else
        {
            ns=a[i]=a[i]+ns;
        }
        //printf("%lld ",a[i]);
    }   
    
    m=a[k-1];
    
    for(i=1;i<n-k+1;++i)
    {
        if(a[i+k-1]-a[i-1]>m)
        {
            m=a[i+k-1]-a[i-1];
        }
    }
    
    printf("%lld",sum+m);
    return 0;
}