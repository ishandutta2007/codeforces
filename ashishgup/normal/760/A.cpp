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
    ll m,d;
    cin>>m>>d;
    ll count=0;
    ll countdays=0;
    ll reqd=0;
    if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
    {
    	reqd=31;
	}
	else if(m==4||m==6||m==9||m==11)
	{
		reqd=30;
	}
	else
	{
		reqd=28;
	}
    while(countdays<reqd)
    {
    	//cout<<countdays<<endl;
    	while(d<=7)
    	{
    		countdays++;
    		d++;
		}
		d=1;
		count++;
	}
	cout<<count;
    return 0;
}