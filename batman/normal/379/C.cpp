////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1 //////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define what_is(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N 300*1001
#define ll long long
ll n,a[N],index[N],m;
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
ll sortt(ll x,ll y){return a[x]<a[y];}
ifstream fin("input.txt");
ofstream fout("output.txt");


int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i],index[i]=i;
	sort(index,index+n,sortt);
	for(int i=0;i<n;i++)
		a[index[i]]=m=max(m+1,a[index[i]]);		
	for(int i=0;i<n;i++)	
		cout<<a[i]<<" ";		
    return 0;
}