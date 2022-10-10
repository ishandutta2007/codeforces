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
    scanf(" %lld",&T);
    LLI cur=0;
    LLI ans=-1;
    while(T--)
    {
        scanf(" %lld",&n);
        ans+=2;
        ans+=abs(cur-n);
        cur=n;
    }
    cout<<ans;
    return 0;
}