#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

typedef long long ll;

const int N=2e5+5;
const int LG=19;

int n;
int a[N], b[N], sparse1[N][LG], sparse2[N][LG];

void build()
{
	for(int i=1;i<=n;i++)
	{
		sparse1[i][0]=a[i];
		sparse2[i][0]=b[i];
	}
	for(int j=1;j<LG;j++)
	{
		for(int i=1;i<=n -(1<<j) + 1;i++)
		{
			sparse1[i][j]=max(sparse1[i][j-1], sparse1[i + (1<<(j-1))][j-1]);
			sparse2[i][j]=min(sparse2[i][j-1], sparse2[i + (1<<(j-1))][j-1]);
		}
	}
}

int querymax(int L, int R)
{
	int answer=INT_MIN;
	for(int j=LG-1;j>=0;j--)
	{
		if(L + (1<<j) - 1 <= R)
		{
			answer=max(answer, sparse1[L][j]);
			L+=(1<<j);
		}
	}
	return answer;
}

int querymin(int L, int R)
{
	int answer=INT_MAX;
	for(int j=LG-1;j>=0;j--)
	{
		if(L + (1<<j) - 1 <= R)
		{
			answer=min(answer, sparse2[L][j]);
			L+=(1<<j);
		}
	}
	return answer;
}

bool check(int i, int k)
{
	long long aval=querymax(i, k);
	long long bval=querymin(i, k);
	if(aval>=bval)
		return 1;
	else
		return 0;
}

bool check2(int i, int k)
{
	long long aval=querymax(i, k);
	long long bval=querymin(i, k);
	if(aval<=bval)
		return 1;
	else
		return 0;
}

int calc(int i)
{
	int lo=i;
	int hi=n;
	int leftr=0;
	while(lo<hi)
	{
		int mid=(lo+hi)>>1;
		if(check(i, mid))
			hi=mid;
		else
			lo=mid+1;
	}
	if(!check(i, lo))
		return 0;
	leftr=lo;
	lo=i;
	hi=n;
	int rightr=0;
	while(lo<hi)
	{
		int mid=(lo+hi+1)>>1;
		if(check2(i, mid))
			lo=mid;
		else
			hi=mid-1;
	}
	rightr=lo;
	if(!check2(i, lo))
		return 0;
	return max(0,rightr-leftr+1);
}

int main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
    	cin>>b[i];
    }
    build();
    long long ans=0;
    for(int i=1;i<=n;i++)
   	{
   		ans+=calc(i);
   	}
   	cout<<ans;
	return 0;
}