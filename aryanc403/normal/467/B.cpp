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
    cin>>n>>m>>k;
    //cout<<n<<m<<k<<endl;
    fo(i,m+1)
    {
		cin>>in;
		a.pb(in);
    }
    LLI cnt=0;
    for(i=0;i<m;i++)
    {
		LLI c=0;
		//cout<<a[i]<<" ";
		for(j=0;j<n;++j)
		{
			//cout<<((a[i]&(1<<j))>0);
			if((a[m]&(1<<j)) ^ (a[i]&(1<<j)))
			{
				c++;
			}
		}
		if(c<=k)
		{
			cnt++;
			//cout<<i<<" ";
			}
		//cout<<endl;
    }
    cout<<cnt;
    return 0;
}