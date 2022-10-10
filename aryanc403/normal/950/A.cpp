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

	LLI T,n,in,i,m,j,cnt,l,r,ans,a;
	vector <LLI> :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>l>>r>>a;

    if(l<r)
    {
        LLI t=l;
        l=r;
        r=t;
    }

    LLI c=l-r;

    if(c<=a)
    {
        a-=c;
        ans=l+a/2;
    }
    else
    {
        ans=r+a;
    }

    cout<<2*ans;

	return 0;
}