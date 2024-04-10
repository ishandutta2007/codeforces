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
    LLI T,n,in,i,m,j,r,l;
    vector <LLI> a;
    vector <LLI> :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    scanf(" %lld",&n);
    a.clear();
    a.reserve(n);
        
        fo(i,n)
        {
            scanf(" %lld",&in);
            a.pb(in);
        }
    bool exist=true;
    
    for(r=n-1;r>0;r--)
    {
        if(a[r]<a[r-1])
            break;
    }
    
    if(r==0)
    {
        cout<<"yes"<<endl<<1<<" "<<1;
        return 0;
    }
    
    for(l=0;l<r;++l)
    {
        if(a[l]>a[r])
        {
            break;
        }
        
        if(a[l]>a[l+1])
        {
        	exist=false;
		}
    }
    //cout<<l<<" "<<r;
    
    for(i=l;i<r;++i)
    {
        if(a[i]<a[i+1])
        {
            exist=false;
            break;
        }
    }
    
    if(r<n-1&&a[l]>a[r+1])
    {
    	exist=false;
	}
    
	if(l&&a[l-1]>a[r])
    {
    	exist=false;
	}
    
    if(exist)
    {
        cout<<"yes"<<endl<<l+1<<" "<<r+1;
    }
    else
    {
        cout<<"no";
    }
    return 0;
}