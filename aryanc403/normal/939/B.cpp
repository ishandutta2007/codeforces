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
#define MAX 100002
#define MOD 1000000007

/*#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
#ifdef LOCAL_TEST
    freopen("in.txt","r",stdin);
#endif*/

    LLI T,n,in,i,m,j,k,p;
    vector <LLI> a,b;
    vector <LLI> :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    k--;
    cin>>p;
    i=1;
    LLI ans=1;

    while(k--)
    {
        i++;
        cin>>in;
        if(n%p>n%in)
        {
            p=in;
            ans=i;
        }
    }
    cout<<ans<<" "<<n/p;
    return 0;
}