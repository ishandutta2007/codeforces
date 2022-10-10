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

    LLI T,n,in,i,m,j,ans[200005],N[200005],ansi;
    vector <LLI> a;
    vector <pair<LLI,LLI> > b;
    vector <LLI> :: iterator it;

LLI mysort(const pair<LLI,LLI> &a,const pair<LLI,LLI> &b)
{
	return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}

LLI bs(LLI x,LLI i)
{
	LLI l,r,mid;
	l=0;
	r=n;
	
	if(x>b[n-1].X)
	    return n;
	
	while(l<r)
	{
		mid=l+(r-l)/2;
		
		if(b[mid].X==x&&b[mid].Y>i)
			r=mid;
		else if(b[mid].X<=x)
			l=mid+1;
		else if(b[mid].X>x)
			r=mid-1;
	}
	return l;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        scanf(" %lld",&n);
        a.clear();
        a.reserve(n);
        
        fo(i,n)
        {
            //in=i%2+1;
            scanf(" %lld",&in);
            a.pb(in);
            //cerr<<in<<" ";
            b.pb(mp(in,i));
        }
    sort(b.begin(),b.end(),mysort);
    LLI cnt=1;
    ansi=n-1;
    for(i=n-1;i>=0;i--)
    {
    	LLI l=bs(a[i]+1,i);
    	//cout<<a[i]+1<<"a "<<l<<"l "<<r<<"r\n";
    	ans[i]=1;
    	N[i]=n;
    	while(l<n&&b[l].X==a[i]+1)
    	{
    		if(i<b[l].Y&&ans[i]<1+ans[b[l].Y])
    		{
    			ans[i]=1+ans[b[l].Y];
    			N[i]=b[l].Y;
    			break;
    		}
    		l++;
		}
		if(cnt<ans[i])
		{
			cnt=ans[i];
			ansi=i;
		}
	}
    
    cout<<cnt<<endl;
    i=ansi;
    while(i<n)
    {
    	cout<<i+1<<" ";
    	i=N[i];
	}
    return 0;
}