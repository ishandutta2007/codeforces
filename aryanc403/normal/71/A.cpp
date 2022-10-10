#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define fo(i,n)   for(i=0;i<n;++i)
#define LLI long long int
#define pb push_back
#define mp make_pair
#define X first
#define Y second

	LLI T,n,in,i;
	//vector <LLI> a;
	//vector <LLI> :: iterator it;
	string a;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    a.reserve(102);
	cin>>T;
	while(T--)
	{
	    cin>>a;
	    
	    if(a.size()>10)
	       cout<<a[0]<<(a.size()-2)<<a[a.size()-1]<<endl;
        else
            cout<<a<<endl;
	}
	return 0;
}