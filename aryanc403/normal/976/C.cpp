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

    LLI T,n,in,i,m,j,k,r,l;
    vector <pair<LLI,pair<LLI,LLI> > > a;
    vector <LLI> :: iterator it;

bool cmp(const pair<LLI,pair<LLI,LLI> > &a,const pair<LLI,pair<LLI,LLI> > &b)//<
{
	if(a.Y.X<b.Y.X)
	{
		return true;
	}
	if(a.Y.X>b.Y.X)
	{
		return false;
	}
	
	if(a.Y.Y<b.Y.Y)
	{
		return false;
	}
	
	if(a.Y.Y>b.Y.Y)
	{
		return true;
	}
	
	return false;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    a.clear();
    a.reserve(n);
    fo(i,n)
    {
    	cin>>l>>r;
    	a.pb(mp(i+1,mp(l,r)));
	}
	sort(a.begin(),a.end(),cmp);
	//fo(i,n)
    {
    //	cout<<(a[i].Y).X<<" "<<(a[i].Y).Y<<endl;
	}
	bool fnd=true;
	
	for(i=0;i<n-1;++i)
	{
		if(a[i].Y.Y>=a[i+1].Y.Y)
		{
			fnd=false;
			r=a[i].X;
			l=a[i+1].X;
			break;
		}
		/*else if(a[i].Y.X==a[i+1].Y.X&&a[i].Y.Y<=a[i+1].Y.Y)
		{
			r=a[i+1].X;
			l=a[i].X;
			fnd=false;
			break;
		}*/
	}
	
	if(fnd)
	{
		l=r=-1;
	}
	cout<<l<<" "<<r;
    return 0;
}