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
    LLI T,n,in,i,m,j,a[4];
    

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a[1]>>a[2]>>n;
    
    a[1]=(a[1]+MOD)%MOD;
    a[2]=(a[2]+MOD)%MOD;
    
    a[3]=a[2]-a[1];
    a[3]=(a[3]+MOD)%MOD;
    
    LLI sign=(n+2)/3;
    
    if(sign%2)
    {
        sign=1;
    }
    else
    {
        sign=-1;
    }
    
    LLI ans;
    
    if(n%3)
    {
        ans=sign*a[n%3];
    }
    else
    {
        ans=sign*a[3];
    }
    
    ans=(ans+MOD)%MOD;
    cout<<ans;
    return 0;
}