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

/*#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
#ifdef LOCAL_TEST
    freopen("in.txt","r",stdin);
#endif*/

	LLI T,n,in,i,m,j;
	vector <LLI> a,b;
	vector <LLI> :: iterator it;
LLI ans()
{
    LLI cnt=0;
    LLI j=0;
    for(LLI i=0;i<n;++i)
    {
        if(a[i]<b[j])
        {
            b[j]-=a[i];
        }
        else if(a[i]==b[j])
        {
            cnt++;
            b[j]=0;
            j++;
        }
        else
        {
            a[i]-=b[j];
            b[j]=0;
            i--;
            j++;
        }
    }
    return cnt;
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	scanf(" %lld %lld",&n,&m);
	a.clear();
	a.reserve(n);
	fo(i,n)
	{
	     scanf(" %lld",&in);
	     a.pb(in);
	}
	b.clear();
	b.reserve(m);
	fo(i,m)
	{
	     scanf(" %lld",&in);
	     b.pb(in);
	}

	cout<<ans();
	return 0;
}