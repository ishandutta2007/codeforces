//for(auto a: x);
#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define LLI long long int
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define MAX 1000002
typedef long long int lli;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef vector<lli> vi;
const lli INF = 0xFFFFFFFFFFFFFFFL;
const lli MOD = 1000000007L;
    lli T,n,in,i,m,j,k;
    vi a;
    vi :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli t=0;
        scanf(" %lld",&n);
        a.clear();
        a.reserve(n);
        
        fo(i,n)
        {
            scanf(" %lld",&in);
            a.pb(in);
        }
    sort(a.begin(),a.end());
    for(k=0;k<n&&a[k]<=500000;++k);
    lli cnt=0;
    if(k)
    {
        cnt=a[k-1]-1;
    }
    if(k<n)
    {
        cnt=max(cnt,1000000-a[k]);
    }
    cout<<cnt;
    return 0;
}