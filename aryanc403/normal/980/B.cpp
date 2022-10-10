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
    LLI T,n,in,i,m,j,k;
    vector <LLI> a;
    vector <LLI> :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    char s[2][n+1];
    cout<<"YES"<<endl;
    fo(i,n)
    {
        cout<<'.';
        s[0][i]=s[1][i]='.';
    }
    cout<<endl;
    s[0][n]=s[1][n]='\0';
    for(i=1;i<=k/4;++i)
    {
        s[0][i]=s[1][i]=s[0][n-i-1]=s[1][n-i-1]='#';
    }
    
    if(k%2)
    {
        k--;
        s[1][n/2]='#';
    }
    if(k%4==2)
    {
        //cout<<i<<endl;
        s[0][n-i-1]=s[0][i]='#';
    }
    
    if(k==2*(n-2))
    {
        s[1][i]='#';
    }
    
    cout<<s[0]<<endl<<s[1]<<endl;
    
    fo(i,n)
        cout<<'.';
    cout<<endl;
    return 0;
}