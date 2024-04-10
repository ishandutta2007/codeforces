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
	cin>>n;
	int arr[n];
	LLI y=1;
	LLI pvr,p,maxi,x;
	cin>>pvr;
	arr[0]=maxi=pvr;
	LLI z,i,j,pi,pj;
	pj=pvr%y+1;

	if(pj==0)
	    pj=y;
	pi=(pvr-pj)/y+1;
	x=pi;
	for(z=1;z<n;++z)
	{
	    cin>>arr[z];
	    p=arr[z];
	    if(abs(pvr-p)!=1)
	    {
	        if(abs(pvr-p)%y==0)
	        {
	            if(abs(pvr-p)>y)
	                y=abs(pvr-p);
	            pj=pvr%y;
	            if(pj==0)
	                pj=y;
	            pi=(pvr-pj)/y+1;
	        }
	        else
	        {
	            cout<<"NO";
	            return 0;
	        }
	    }
	    j=p%y;
	    if(j==0)
	        j=y;
	    i=(p-j)/y+1;

	    //cout<<p<<" "<<i<<" "<<j<<" "<<pvr<<" "<<pi<<" "<<pj<<" "<<y<<"\n";
	    if(abs(i-pi)+abs(j-pj)!=1)
	    {
	        cout<<"NO";
	        return 0;
	    }

	    pvr=p;
	    pi=i;
	    pj=j;
	    if(maxi<p)
	        maxi=p;
	    if(x<i)
	        x=i;
	}
	pvr=arr[0];
	pj=pvr%y;
	    if(pj==0)
	        pj=y;
         pi=(pvr-pj)/y+1;
	    
	for(z=1;z<n;++z)
	{
	    p=arr[z];
	    j=p%y;
	    if(j==0)
	        j=y;
	    i=(p-j)/y+1;
	    //cout<<p<<" "<<i<<" "<<j<<" "<<pvr<<" "<<pi<<" "<<pj<<" "<<y<<"\n";
	    if(abs(i-pi)+abs(j-pj)!=1)
	    {
	        cout<<"NO";
	        return 0;
	    }
	    pvr=p;
	    pi=i;
	    pj=j;
	}

	cout<<"YES\n";
	cout<<x<<" "<<y;
	return 0;
}