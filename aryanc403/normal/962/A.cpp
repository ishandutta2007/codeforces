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
    //scanf(" %lld",&T);
    //while(T--)
    {
        scanf(" %lld",&n);
        a.clear();
        a.reserve(n);
        LLI sum=0;
        fo(i,n)
        {
            scanf(" %lld",&in);
            a.pb(in);
            sum+=in;
        }
        LLI c=0;
        fo(i,n)
        {
            c+=a[i];
            if(c>=(sum+1)/2)
                break;
        }
        
        printf("%lld\n",i+1);
    }
    return 0;
}