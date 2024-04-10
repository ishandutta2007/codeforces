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
int p=-1;
int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='h' && p==-1)
			p=0;
		else if(s[i]=='e' && p==0)
			p=1;
		else if(s[i]=='l' && p==1)
			p=2;
		else if(s[i]=='l' && p==2)
			p=3;
		else if(s[i]=='o' && p==3)
		{
			cout<<"YES";
			return 0;
		}	
					
			
	}
	cout<<"NO";
    return 0;
}