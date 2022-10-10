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
    string s;
    vector <LLI> :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    bool ln[n+1];
    
    for(i=1;i<=n;++i)
    {
    	ln[i]=true;
    	LLI tmp=i;
    	while(tmp)
    	{
    		if(tmp%10!=4&&tmp%10!=7)
    			ln[i]=false;
    		tmp/=10;
		}
	}
    
    if(ln[n])
    {
    	cout<<"YES";
    	return 0;
	}
	
	for(i=1;i<=n;++i)
	{
		if(n%i==0&&ln[i])
		{
			cout<<"YES";
    		return 0;
		}
	}
    cout<<"NO";
    return 0;
}