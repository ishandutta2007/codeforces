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

/*#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
#ifdef LOCAL_TEST
    freopen("in.txt","r",stdin);
#endif*/

    LLI T,n,in,i,m,j;
    vector <LLI> a;
    vector <LLI> :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    scanf(" %lld",&n);
    
    if(n<6)
        printf("-1\n");
    else
    {
        printf("1 2\n");
        printf("1 3\n");
        printf("1 4\n");
        //printf("2 5\n");
        //printf("2 6\n");
        for(LLI i=5;i<=n;++i)
            printf("2 %lld\n",i);
    }
    
    for(LLI i=2;i<=n;++i)
        printf("1 %lld\n",i);
    
    return 0;
}