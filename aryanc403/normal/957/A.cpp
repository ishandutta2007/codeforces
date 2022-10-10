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

    LLI T,n,in,i,m,j,k,p,a,b;
    //vector <LLI> a,b;
    string s;
    vector <LLI> :: iterator it;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    cin>>s;
    bool way=false,b=true;
    //cout<<s;
    if(s[0]=='?'||s[n-1]=='?')
        way=true;
    
    for(int i=1;i<n-1;++i)
    {
        if(s[i]=='?')
        {
            if(s[i-1]==s[i+1]&&s[i-1]!='?')
            {
                way=true;
            }
            else if(s[i-1]==s[i])
            {
                way=true;
            }
        }
        
        if(s[i-1]==s[i]&&s[i]!='?')
        {
            b=false;
        }
    }
    
    if(s[n-2]==s[n-1]&&s[n-1]!='?')
    {
        b=false;
    }
    
    if(way&&b)
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
    return 0;
}