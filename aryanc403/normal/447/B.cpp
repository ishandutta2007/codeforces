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
    string s;
    cin>>s;
        cin>>k;
        a.clear();
        a.reserve(26);
        m=0;
        fo(i,26)
        {
            cin>>in;//scanf(" %lld",&in);
            a.pb(in);
            //cout<<in<<" ";
            m=max(m,in);
        }
    LLI val=0;
    fo(i,s.size())
    {
        val+=(i+1)*a[s[i]-'a'];
    }
    
    j=i+k;
    
    val+=m*(j*(j+1)-i*(i+1))/2;
    cout<<val;
    return 0;
}