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

int n;
bool check(int x)
{
	while(x)
	{
		if(x%10!=4 && x%10!=7)
			return false;
		x/=10;	
	}
	return true;
}

int main()
{
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		if(n%i==0)
			if(check(i)==true)
			{
				cout<<"YES";
				return 0;
			}

	}
	cout<<"NO";
    return 0;
}