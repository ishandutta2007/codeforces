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
string s;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    cin>>s;
LLI cnt=0;    
    for(i=0;i<n-2;++i)
    {
        if(s[i]=='x'&&s[i+1]=='x'&&s[i+2]=='x')
        {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}