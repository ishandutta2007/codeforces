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
    LLI T,n,in,i,m,j,k,ma[5005][5005],dp[5005][5005];
    vector <LLI> a;
    vector <LLI> :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        scanf(" %lld",&n);
        a.clear();
        a.reserve(n+1);
        a.pb(0);
        fo(i,n)
        {
            scanf(" %lld",&in);
            a.pb(in);
            dp[i+1][1]=ma[i+1][1]=in;
        }
    
    for(j=2;j<=n;++j)
    {
        for(i=1;i+j<=n+1;++i)
        {
            dp[i][j]=dp[i][j-1]^dp[i+1][j-1];
            ma[i][j]=max(dp[i][j],max(ma[i][j-1],ma[i+1][j-1]));
        }
    }
    LLI q;
    scanf(" %lld",&q);
    LLI l,r;
    while(q--)
    {
        scanf(" %lld %lld",&l,&r);
        i=l;
        j=r-l+1;
        printf("%lld\n",ma[i][j]);
    }
    
    return 0;
}