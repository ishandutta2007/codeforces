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

	LLI T,n,in,i,cnt,k;
	vector <LLI> a;
	//vector <LLI> :: iterator it;
	//string a;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    a.reserve(102);
	cin>>n>>k;
	a.reserve(n);
	
	fo(i,n)
    {
        cin>>in;
        a.pb(in);
    }
    
    fo(i,k)
    {
        if(a[i]>0)
        {
            cnt++;
        }
        else
        {
            break;
        }
    }
    
    for(i=k;i<n;++i)
    {
        if(a[i]>0&&a[i]==a[i-1])
        {
            cnt++;
        }
        else
        {
            break;
        }
    }
    cout<<cnt;
	return 0;
}