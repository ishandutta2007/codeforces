////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.0 //////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define what_is(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N 
#define ll long long
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
ifstream fin("input.txt");
ofstream fout("output.txt");

ll n,m,k;
bool a[1100][1100];
int main()
{
	cin>>n>>m>>k;
	for(int i=0;i<k;i++)
	{
		ll x,y;
		cin>>x>>y;
		a[x][y]=true;
		if((a[x-1][y]==true && a[x][y-1]==true && a[x-1][y-1]==true) || (a[x-1][y]==true && a[x-1][y+1]==true && a[x][y+1]==true) || (a[x][y+1]==true && a[x+1][y]==true && a[x+1][y+1]==true) || (a[x][y-1]==true && a[x+1][y]==true && a[x+1][y-1]==true))
		{
			cout<<i+1;
			return 0;
		}
		
	}
	cout<<0;
    return 0;
}