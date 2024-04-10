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
    vector <LLI> :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
	a.clear();
    a.reserve(n);
    
    fo(i,m)
    {
		cin>>in;
		a.pb(in);
    }
    
    LLI c1=0,c2=0;
    LLI cur=1;
    fo(i,m)
    {
    	if(cur<=a[i])
    	c1+=a[i]-cur;
    	else
    	{
    		c1+=a[i]+n-cur;
		}
		cur=a[i];
	}
    
    /*fo(i,m)
    {
    	if(cur>=a[i])
    		c2+=cur-a[i];
    	else
    	{
    		c2+=cur+n-a[i];
		}
		cur=a[i];
	}*/
    
    cout<<c1;
    return 0;
}