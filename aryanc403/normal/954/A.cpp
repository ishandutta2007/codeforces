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

	LLI T,n,in,i,m,j,cnt,l;
	string s;
	vector <LLI> :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin>>l;
	cin>>s;
	cnt=0;

	for(int i=0;i<l;++i)
	{
	    if((s[i]=='U'&&s[i+1]=='R')||(s[i]=='R'&&s[i+1]=='U'))
	    {
	        cnt++;
	        i++;
	    }
	}
	cout<<l-cnt;
	return 0;
}