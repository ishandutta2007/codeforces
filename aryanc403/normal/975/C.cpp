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
    LLI T,n,in,i,m,j,k,q;
    vector <LLI> a;
    vector <LLI> :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>q;
        a.clear();
        a.reserve(n);
        LLI sum=0;
        fo(i,n)
        {
            cin>>in;//scanf(" %lld",&in);
            sum+=in;
            a.pb(sum);
            //cout<<in<<" ";
        }
        //cout<<endl;
    sum=0;
    LLI cnt;
    while(q--)
    {
        cin>>in;
        sum+=in;
        //cout<<sum<<" ";
        cnt=upper_bound(a.begin(),a.end(),sum)-a.begin();
        if(cnt==n)
        {
            sum=0;
            cout<<cnt<<endl;
        }
        else
        {
            cout<<n-cnt<<endl;
        }
    }
    
    return 0;
}