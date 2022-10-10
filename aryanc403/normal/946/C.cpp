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

    LLI T,n,in,i,m,j,k,p,a,b;
    //vector <LLI> a,b;
    string s;
    vector <LLI> :: iterator it;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    char c='z';
    for(i=s.size()-1;i>=0&&c>='a';i--)
    {
        if(s[i]<=c)
        {
            s[i]=c;
            c--;
        }
    }
    //cout<<c;
    if(c>='a')
    {
        cout<<-1;
        return 0;
    }
    cout<<s;
    return 0;
}