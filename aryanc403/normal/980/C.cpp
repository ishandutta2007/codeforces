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
    LLI T,n,in,i,m,j,k,r,grp[300];
    vector <LLI> :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    scanf(" %lld %lld",&n,&k);
    for(i=0;i<=256;++i)
    {
        grp[i]=-1;
    }
    grp[0]=0;
    fo(i,n)
    {
        scanf(" %lld",&in);
        if(grp[in]!=-1)
        {
        	cout<<grp[in]<<" ";
        	continue;
		}
		for(j=0;j<k&&j<in;++j)
        {
            if(grp[in-j]!=-1)
            	break;
        }
        
        LLI c = in-j,ind = in - j;
        
        if(j==k)
        {
        	j--;
        	LLI val = in - j;
        	for(j=val;j<=in;++j)
        	{
        		grp[j]=val;
			}	
		}
		else
		{
			LLI val = grp[in-j];
			if(in-val<k)
			{
				for(j=val+1;j<=in;++j)
					grp[j]=val;
			}
			else
			{
				val = in - j +1;
				for(j=val;j<=in;++j)
					grp[j]=val;
			}
		}
        cout<<grp[in]<<" ";
        /*cout<<endl;
        for(j=0;j<20;++j)
        {
        	cout<<grp[j]<<" ";
		}
        cout<<endl;*/
    }
    return 0;
}