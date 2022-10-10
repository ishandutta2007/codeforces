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

    LLI T,n,in,i,m,j,k,c,l;
    LLI cnt[101][101];
    vector <LLI> :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    char s[n+1][n+1];
    bool t;
    for(i=0;i<n;++i)
    {
        cin>>s[i];
        //cout<<s[i]<<endl;
    }
    
    //cols
    for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
        {
            if(j+k>n)
            {
                break;
            }
            t=true;
            for(l=j;l<j+k;++l)
            {
                if(s[i][l]=='#')
                {
                    t=false;
                    break;
                }
            }
            if(t)
            {
                for(l=j;l<j+k;++l)
                {
                    cnt[i][l]++;
                }
            }
        }
    }
    
    //rows
    for(i=0;i<n;++i)
    {
        if(i+k>n)
        {
            break;
        }
        for(j=0;j<n;++j)
        {
            //cout<<1<<" ";
            t=true;
            for(l=i;l<i+k;++l)
            {
                if(s[l][j]=='#')
                {
                    t=false;
                    break;
                }
            }
            if(t)
            {
                for(l=i;l<i+k;++l)
                {
                    cnt[l][j]++;
                }
            }
        }
        //cout<<"\n";
    }
    //cout<<"\n\n";
    LLI maxi=0;
    LLI x=1,y=1;
    
    for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
        {
            //cout<<cnt[i][j]<<" ";
            if(maxi<cnt[i][j])
            {
                maxi=cnt[i][j];
                x=i+1;
                y=j+1;
            }
        }
        //cout<<endl;
    }
    
    cout<<x<<" "<<y;
    //cout<<endl<<cnt[0][7]<<" "<<cnt[12][8];
    return 0;
}