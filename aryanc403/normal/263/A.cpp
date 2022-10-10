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

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    for(i=1;i<=5;++i)
    {
    	for(j=1;j<=5;++j)
    	{
    		cin>>in;
    		if(in)
    			break;
    	}
    	if(in)
    		break;
	}
    //cout<<i<<" "<<j<<endl;
    cout<<abs(3-i) + abs(3-j);
    
    return 0;
}