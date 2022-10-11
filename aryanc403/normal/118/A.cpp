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

	LLI T,n,in,i,cnt,k,m;
	//vector <LLI> :: iterator it;
	//string a;
	char a[102];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a;
	//swap(n,m);
    n=strlen(a);
    
    fo(i,n)
    {
        if(a[i]>='A'&&a[i]<='Z')
        {
            a[i]+=32;
        }
        
        if(a[i]!='a'&&a[i]!='o'&&a[i]!='y'&&a[i]!='e'&&a[i]!='u'&&a[i]!='i')
        {
            cout<<'.'<<a[i];
        }
    }
	return 0;
}