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

/*#ifdef LOCAL_TEST
    freopen("in.txt","r",stdin);
#endif*/

	LLI T,n,in,i,m,j,hh,mm,h,d,c;
	vector <LLI> a;
	vector <LLI> :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin>>hh>>mm;
	cin>>h>>d>>c>>n;

	if(hh>=20)
	{
	    LLI tB=ceil(h/(double)n);
	    cout<<(.80*tB*c);
	    return 0;
	}
	LLI tB=ceil(h/(double)n);
	LLI ci=tB*c;

	h+=((20-hh)*60-mm)*d;
	tB=ceil(h/(double)n);

	printf("%f",min((double)ci,.80*tB*c));//cout<<min((double)ci,.80*tB*c);
	return 0;
}