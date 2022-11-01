////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1 //////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define what_is(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N 110
#define ll long long
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
ifstream fin("input.txt");
ofstream fout("output.txt");

int n,k,ans;
bool mark[10];
string s;
int main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		int subans=0;
		cin>>s;
		for(int j=0;j<10;j++)
			mark[j]=false;
		for(int j=0;j<s.size();j++)
		{
			int ex=s[j]-'0';
			//cout<<ex<<" ";
			if(mark[ex]==false && ex<=k)
			{
				mark[ex]=true;
				subans++;
			}
			if(subans==k+1)
			{
				ans++;
				break;
			}
		}	
	}
	cout<<ans<<endl;
	
		
    return 0;
}