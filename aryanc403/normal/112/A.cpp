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

    LLI T,n,in,i,m,j,t;
    string a,b;
    vector <LLI> :: iterator it;

LLI cmp()
{
    for(i=0;i<a.size();++i)
    {
        if(a[i]<='Z'&&a[i]>='A')
            a[i]+=32;
        if(b[i]<='Z'&&b[i]>='A')
            b[i]+=32;
        
        if(a[i]<b[i])
            return -1;
        if(a[i]>b[i])
            return 1;
    }
    
    return 0;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>a>>b;
    cout<<cmp();
    return 0;
}