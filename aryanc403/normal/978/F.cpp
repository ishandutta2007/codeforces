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
    LLI T,n,in,i,m,j,k,x,y,cnt[200005];
    vector <LLI> a,b;
    vector <LLI> :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
        a.clear();
        a.reserve(n+1);
        b.clear();
        b.reserve(n+1);
        a.pb(0);
        fo(i,n)
        {
            cin>>in;//scanf(" %lld",&in);
            a.pb(in);
            b.pb(in);
        }
    sort(b.begin(),b.end());
    while(k--)
    {
        cin>>x>>y;
        if(a[x]>a[y])
        {
            cnt[x]--;
        }
        else if(a[x]<a[y])
        {
            cnt[y]--;
        }
    }
    b.pb(b[n-1]+10);
    for(i=1;i<=n;++i)
    {
        j=lower_bound(b.begin(),b.end(),a[i])-b.begin();
        cout<<j+cnt[i]<<" ";
    }
    return 0;
}