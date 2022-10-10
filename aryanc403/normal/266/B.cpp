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

    LLI T,n,in,i,m,j,t;
    string s;
    vector <LLI> :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>t;
    cin>>s;
    bool a[100];
    for(LLI i=0;i<t;++i)
    {
    	a[n]=true;
        for(LLI j=n-1;j>=0;--j)
        {
            if(s[j]=='B'&&s[j+1]=='G'&&a[j+1])
            {
                s[j+1]='B';
                s[j]='G';
                a[j]=false;
            }
            else
            {
            	a[j]=true;
			}
        }
    }
    cout<<s;
    return 0;
}