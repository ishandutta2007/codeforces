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

ll a,b,n;


int main()
{
	cin>>a>>b>>n;
	for(int i=0;;i++)
	{
		ll p=a,p2=0;
		if(i%2==1)
			p=b,p2=1;
		if(n-gcd(n,p)==0)
		{
			cout<<p2;
			return 0;
		}
		n-=gcd(n,p);
	}
    return 0;
}