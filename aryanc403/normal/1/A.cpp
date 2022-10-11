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

	LLI T,n,in,i,m,a;
	//vector <LLI> a;
	vector <LLI> :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	scanf(" %lld %lld %lld",&n,&m,&a);
	//a.clear();
	//a.reserve(n);

    //fo(i,n)
    {
      //  scanf(" %lld",&in);
        //a.pb(in);
    }
    printf("%lld\n",(LLI)(ceil(n/(double)a)*ceil(m/(double)a)));
	return 0;
}