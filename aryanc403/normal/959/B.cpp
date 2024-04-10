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

    LLI T,n,in,i,M,j,k;
    vector <LLI> a;
    vector <LLI> :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k>>M;//scanf(" %lld %lld %lld",&n,&k,&m);
    string s[n];
    for(i=0;i<n;++i)
    {
        cin>>s[i];
    }
    
    int cost[n];
    for(i=0;i<n;++i)
    {
        cin>>cost[i];
    }
    
    for(i=0;i<k;++i)
    {
        vector <LLI> a;
        a.clear();
        LLI n;
        cin>>n;
        a.reserve(n);
        LLI min=0;
        for(int j=0;j<n;++j)
        {
            cin>>in;
            in--;
            a.pb(in);
            if(j==0||cost[in]<min)
            {
                min=cost[in];
            }
        }
        for(int j=0;j<n;++j)
        {
            cost[a[j]]=min;
        }
    }
    unordered_map < string , LLI > m;
    for(i=0;i<n;++i)
    {
        m[s[i]]=cost[i];
        //cout<<s[i]<<" "<<m[s[i]]<<endl;
    }
    string str;
    LLI ans=0;
    for(i=0;i<M;++i)
    {
        cin>>str;
        ans+=m[str];
    }
    cout<<ans;
    return 0;
}