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
    LLI T,n,in,i,m,j,a,b;
    string s;
    vector <LLI> :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>a>>b;
    cin>>s;
    
    LLI cnt,c;
    c=0;
    cnt=0;
    
    if(b>a)
    {
        a = a+b - (b=a);
    }
    
    fo(i,n)
    {
        if(s[i]=='*')
        {
            c=0;
            if(b>a)
            {
                a = a+b - (b=a);
            }
            continue;
        }
        if(c%2)
        {
            if(b>0)
            {
                cnt++;
                b--;
            }
        }
        else
        {
            if(a>0)
            {
                cnt++;
                a--;
            }
        }
        c++;
    }
    cout<<cnt;
    return 0;
}