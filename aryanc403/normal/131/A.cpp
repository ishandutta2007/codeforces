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

	LLI T,n,in,i,m,j;
	vector <LLI> a;
	vector <LLI> :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string s;
	cin>>s;
	bool chg=true;
	n=s.size();
	for(i=1;i<n&&chg;++i)
	{
	    chg=(s[i]<='Z')&&(s[i]>='A');
	}
	
	if(chg)
	{
	    i=0;
	    if((s[i]<='z')&&(s[i]>='a'))
	        s[i]-=32;
	    else
	        s[i]+=32;
	    for(i=1;i<n;++i)
	    {
	        s[i]+=32;
	    }
	}
	
	cout<<s;
	return 0;
}