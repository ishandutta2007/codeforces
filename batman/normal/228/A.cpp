////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.0 //////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define what_is(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N 
#define ll long long
#define DELTA 1000
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
ifstream fin("input.txt");
ofstream fout("output.txt");

ll s[4],ans=4,p,a[4];
int main()
{
	for(int i=0;i<4;i++)
	{
		int ex=0;
		cin>>s[i];
		for(int j=0;j<p;j++)
			if(s[i]==a[j])
				ex++;
				
		if(ex==0)
		{
			a[p]=s[i];
			p++;
		}
					
	}
	cout<<4-p;
	
    return 0;
}