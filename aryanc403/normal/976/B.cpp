
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

    LLI T,n,in,i,m,j,k;
    vector <LLI> a;
    vector <LLI> :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>k;
    LLI r,c;
    if(k<n)
    {
    	r=k+1;
    	c=1;
	}
	else
	{
		k-=n;
		r=n-k/(m-1);
		c=(k%(m-1));
		if((n-r)%2==0)
			c+=2;
		else
			c=m-c;
	}
	cout<<r<<" "<<c;
    return 0;
}