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
    string s;
    vector <LLI> :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    LLI yy;
    yy=n/m;
    LLI c=n%m;
    
    LLI cnt=0;
    cnt+=c*(yy+1)*yy/2;
    cnt+=(m-c)*yy*(yy-1)/2;    
    LLI zz=0;
    zz=n-m+1;
    cout<<cnt<<" "<<(zz)*(zz-1)/2;
    return 0;
}