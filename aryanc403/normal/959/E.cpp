//for(auto a: x);
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include<stdio.h>
#define fo(i,n)   for(i=0;i<(n);++i)
#define ll long long
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

long long dp[50];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    scanf(" %I64d",&n);
    ll ans=0;
    n--;
    for(ll i=1;i<41;++i)
    {
        dp[i]=2LL*dp[i-1]+(1LL<<(i-1));
    }
    for(ll i=0;i<50;++i)
    {
        if(n&(1LL<<i))
        {
            ans+=dp[i]+(1LL<<i);
        }
    }
    printf("%I64d",ans);
    return 0;
}