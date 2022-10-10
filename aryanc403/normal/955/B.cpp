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
    LLI T,n,in,i,m,j,c[26];
    vector <LLI> a;
    vector <LLI> :: iterator it;
    string s;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    for(i=0;i<s.size();++i)
        c[s[i]-'a']++;
    
    LLI d=0,e=0;
    for(i=0;i<26;++i)
    {
        d+=(c[i])>0;
        e+=(c[i])>1;
    }
        
    if(d<2||d>4)
    {
        cout<<"No";
        return 0;
    }
    
    if(d==4||(d==3&&e)||(d==2&&e>1))
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
    
    return 0;
}