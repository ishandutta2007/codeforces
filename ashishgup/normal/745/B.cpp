#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define fr(i,s,e) for(i=s;i<e;i++)
#define rf(i,s,e) for(i=s-1;i>=e;i--)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<long long,long long> > vpll;
typedef vector<vector<ll> > vvll;

#define PI 3.141592653589793
#define MOD 1000000007

int main()
{
    ll n,m;
    cin>>n>>m;
    vector< vector<char> > v= vector< vector<char> > (n,vector<char>(m,' '));
    for(ll i=0;i<n;i++)
    {
    	for(ll j=0;j<m;j++)
    	{
    		cin>>v[i][j];
		}
	}
    pair<ll,ll> tl,tr,bl,br;
    bool tlc=true,trc=true,blc=true,brc=true;
    for(ll i=0;i<n;i++)
    {
    	
    	for(ll j=0;j<m;j++)
    	{
    		if(v[i][j]=='X'&&tlc)
    		{
    			tl.first=i;
    			tl.second=j;
    			tr.first=i;
    			tr.second=j;
    			tlc=false;
			}
			if(v[i][j]=='X'&&tlc==false&&trc==true)
			{
				tr.first=i;
				tr.second=j;
			}
		}
		if(tlc==false)
		{
			break;
		}
	}
	for(ll i=n-1;i>=0;i--)
    {
    	
    	for(ll j=m-1;j>=0;j--)
    	{
    		if(v[i][j]=='X'&&brc)
    		{
    			br.first=i;
    			br.second=j;
    			bl.first=i;
    			bl.second=j;
    			brc=false;
			}
			if(v[i][j]=='X'&&brc==false&&blc==true)
			{
				bl.first=i;
				bl.second=j;
			}
		}
		if(brc==false)
		{
			break;
		}
	}
	bool check=true;
	if(bl.second!=tl.second||br.second!=tr.second)
	{
	    check=false;
	}
	/*cout<<tl.first<<" "<<tl.second<<endl;
	cout<<tr.first<<" "<<tr.second<<endl;
	cout<<bl.first<<" "<<bl.second<<endl;
	cout<<br.first<<" "<<br.second<<endl;*/
	if(check)
	{
	    for(ll i=tl.first;i<=bl.first;i++)
    	{
    	    for(ll j=tl.second;j<=tr.second;j++)
    	    {
    	        if(v[i][j]!='X')
    	        {
    	            check=false;
    	        }
    	    }
    	}
	}
	if(check)
	{
	    cout<<"YES";
	}
	else
	{
	    cout<<"NO";
	}
    return 0;
}