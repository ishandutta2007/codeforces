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
	string s,t;
	cin>>s>>t;
	ll n=s.size();
	vector<ll> chareq(26,0);
	for(ll i=0;i<26;i++)
	{
		chareq[i]='.';
	}
	vector<bool> visited(26,false);
	bool check=true;
	vector<char> ans1;
	vector<char> ans2;
	ll size=0;
	for(ll i=0;i<n;i++)
	{
		char ch=s[i];
		int original=s[i]-'a';
		int new1=chareq[original];
		char chnew=(char)(new1+'a');
		if(chnew!=t[i])
		{
			if(visited[original]==false)
			{
				visited[original]=true;
				int replace=t[i]-'a';
				chareq[original]=replace;
				chareq[replace]=original;
				if(replace!=original)
    			{
    			    if(visited[replace]==true)
    				{
    				    check=false;
    				}
    			    visited[replace]=true;
    			    ans1.push_back(ch);
    				ans2.push_back(t[i]);
    				size++;
    			}
			}
			else
			{
				check=false;
			}
		}
	}
	if(check==false)
	{
		cout<<"-1";
	}
	else
	{
		if(size==0)
		{
			cout<<"0";
		}
		else
		{
			cout<<size<<endl;
			for(ll i=0;i<size;i++)
			{
				cout<<ans1[i]<<" "<<ans2[i]<<endl;
			}
		}
	}
	return 0;
}