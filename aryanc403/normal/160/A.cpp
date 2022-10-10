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
    cin>>n;
    LLI sum=0,ab=0;
    fo(i,n)
    {
		cin>>in;
		a.pb(in);
		sum+=in;
    }
    sort(a.begin(),a.end());
    LLI cnt=0;
    for(i=n-1;i>=0;i--)
    {
		if(ab*2>sum)
			break;
		ab+=a[i];
		cnt++;
    }
    cout<<cnt;
    return 0;
}