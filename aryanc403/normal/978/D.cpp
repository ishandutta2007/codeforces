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
    LLI T,n,in,i,m,j,k,D[10],cnt[3][14];
    vector <LLI> a,d,b,c;
    vector <LLI> :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        scanf(" %lld",&n);
        a.clear();
        a.reserve(n);
        d.clear();
        d.reserve(n-1);
        fo(i,n)
        {
            scanf(" %lld",&in);
            a.pb(in);
            if(i)
            {
                d.pb(a[i]-a[i-1]);
            }
        }
    
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    
    sort(d.begin(),d.end());
    
    if(d[n-2]-d[0]>4)
    {
        cout<<-1;
        return 0;
    }
    D[4]=d[0];
    for(i=1;i<=4;++i)
    {
        D[i+4]=D[4]+i;
        D[4-i]=D[4]-i;
        D[i+8]=D[4]+i+4;
    }
    
    for(i=0;i<n;++i)
    {
        for(j=0;j<13;++j)
        {
            for(k=-1;k<=1;++k)
            {
                if(cnt[k+1][j]!=MOD)
                {
                    LLI c=abs(a[i]-(a[0]+k)-i*D[j]);
                    cnt[k+1][j]+=c;
                    //cout<<i<<" "<<D[j]<<" "<<c<<endl;
                    if(c>1)
                    {
                        cnt[k+1][j]=MOD;
                    }
                }
            }
        }
        //cout<<endl<<endl;
    }
    LLI c=MOD;
    for(k=0;k<3;++k)
    for(j=0;j<13;++j)
    {
        //cout<<D[j]<<" ";
        c=min(c,cnt[k][j]);
    }
    if(c==MOD)
        c=-1;
    cout<<c;
    return 0;
}