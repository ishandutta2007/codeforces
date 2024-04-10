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
    LLI T,n,in,i,m,j;
    vector <LLI> a;
    vector <LLI> :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LLI r,x1,y1,x2,y2;
    cin>>r>>x1>>y1>>x2>>y2;
    double d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    LLI n;
    n=ceil(d/(2*r));
    cout<<n;
    return 0;
}