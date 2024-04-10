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
    LLI T,n,in,i,m,j;
    vector < pair<string,string> > a;
    string b,c;
    vector <LLI> :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
        //scanf(" %lld %lld",&n,&m);
        cin>>n>>m;
		a.clear();
        a.reserve(m);
        
        fo(i,m)
        {
        	cin>>b;
        	cin>>c;
            a.pb(mp(b,c));
        }
        
    //fo(i,m)
    {
    //	cout<<a[i].X<<" "<<a[i].Y<<endl;
	}
	
	while(n--)
	{
		cin>>c;
		fo(i,m)
		{
			if(a[i].X==c)
				break;
		}
		
		cout<<(a[i].X.size()>a[i].Y.size()?a[i].Y:a[i].X)<<" ";
	}
	
    return 0;
}