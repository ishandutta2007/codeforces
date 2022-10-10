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

#ifdef LOCAL_TEST
    freopen("in.txt","r",stdin);
#endif
	LLI T,n,in,i,m,j;
	vector <LLI> a;
	vector <LLI> :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	scanf(" %lld",&n);
	a.clear();
	a.reserve(n+1);
	a.pb(0);
	fo(i,n)
	{
        scanf(" %lld",&in);
        a.pb(in);
	}

	for(i=1;i<=n;++i)
	{
	    if(i==a[a[a[i]]])
	    {
	        cout<<"YES";
	        return 0;
	    }
	}

	cout<<"NO";
	return 0;
}