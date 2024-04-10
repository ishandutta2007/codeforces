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
    LLI T,n,in,i,m,j;
    vector <LLI> a;
    string s;
    vector <LLI> :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
	a.clear();
    a.reserve(102);
    
    fo(i,s.size())
    {
		if(s[i]>='1'&&s[i]<='3')
		a.pb(s[i]-48);
    }
    sort(a.begin(),a.end());
    j=0;
    fo(i,s.size())
    {
		if(s[i]>='1'&&s[i]<='3')
		s[i]=a[j++]+'0';
    }
    cout<<s;
    return 0;
}