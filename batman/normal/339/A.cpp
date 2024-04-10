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

string s;
int a[200];
int main()
{
	cin>>s;
	for(int i=0;i<s.size();i+=2)
		a[i/2]=s[i]-'0';		
	sort(a,a+s.size()/2+1);
	for(int i=0;i<s.size()/2+1;i++)
	{
		if(i==0)
			cout<<a[i];
		else
			cout<<"+"<<a[i];	
	}
		
    return 0;
}