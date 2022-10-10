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
    LLI T,n,in,i,m,j,l,x,y;
    vector <pair<LLI,LLI> > a,b;
    vector <LLI> :: iterator it;

bool colliner(const pair<LLI,LLI> &a,const pair<LLI,LLI> &b,const pair<LLI,LLI> &c)
{
	return (c.X-a.X)*(b.Y-a.Y)==(b.X-a.X)*(c.Y-a.Y);
}

bool check(LLI x,LLI y)
{
	vector <pair<LLI,LLI> > c;
	c.clear();
	LLI cnt=0;
	fo(i,n)
	{
		if(colliner(a[i],b[x],b[y])==false)
		{
			//cout<<"return i"<<i<<" x"<<x<<" y"<<y<<" z"<<z<<endl;
			c.pb(a[i]);
			cnt++;
		}
	}
	
	for(i=2;i<cnt;++i)
	{
		if(colliner(c[i],c[0],c[1])==false)
		{
			return false;
		}
	}
	
	return true;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    if(n<=3)
    {
    	cout<<"YES";
    	return 0;
	}
    a.reserve(n);
	for(i=0;i<n;++i)
    {
    	cin>>x>>y;
    	a.pb(mp(x,y));
    	if(i<=1)
    	{
    		b.pb(mp(x,y));
		}
		else if(b.size()==2&&(colliner(b[0],b[1],mp(x,y))==false))
		{
			b.pb(mp(x,y));
		}
    }
    //cout<<"bool"<<colliner(b[0],b[1],b[2])<<endl;
    /*fo(i,3)
    {
    	cout<<b[i].X<<" b "<<b[i].Y<<endl;
	}*/
    if(b.size()==2||check(0,1)||check(0,2)||check(1,2))
    {
    	cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
    
    return 0;
}