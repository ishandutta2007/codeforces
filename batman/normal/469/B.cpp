////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1 //////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define what_is(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N 
#define ll long long
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
//bool sortt(int x,int y){ return a[x] > a[y]; }
ifstream fin("input.txt");
ofstream fout("output.txt");

int p,q,l,r,a,b;

bool mark[1100],mark2[1100];
int main()
{ 
    cin>>p>>q>>l>>r;
    for(int i=0;i<p;i++)
    {
    	cin>>a>>b;
    	for(int j=a;j<=b;j++)
    		mark[j]=true;
    }
    for(int i=0;i<q;i++)
    {
    	cin>>a>>b;
    	for(int j=a;j<=b;j++)
    		mark2[j]=true;
    }
    int ans=0;
    for(int i=l;i<=r;i++)
    {
    	for(int j=0;j<1100;j++)
    	{
    		if(j-i>=0)
    		if(mark[j]==true && mark2[j-i]==true)
    		{
    			ans++;
    			break;
    		}
    	}
    }
    cout<<ans<<endl;
    return 0;
}