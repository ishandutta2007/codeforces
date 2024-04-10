#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;
const int LG=18;

int n;
int a[N];
int sparse[N][LG];
map<int, long long> m;

void buildsparse()
{
	for(int i=1;i<=n;i++)
		sparse[i][0]=a[i];
	for(int j=1;(1<<j)<=n;j++)
	{
		for(int i=1;(i + (1<<j) - 1)<=n;i++)
		{
			sparse[i][j]=__gcd(sparse[i][j-1], sparse[i + (1<<(j-1))][j-1]);
		}
	}
} 

int query(int L, int R)
{
	int j=log2(R-L+1);
	return __gcd(sparse[L][j], sparse[R - (1<<j) + 1][j]);
}

int binsearch(int start, int lo, int hi, int shouldbe)
{
	while(lo<hi)
	{
		int mid=(lo+hi+1)>>1;
		if(query(start, mid)==shouldbe)
			lo=mid;
		else
			hi=mid-1;
	}
	return lo;
}

void work()
{
	for(int i=1;i<=n;i++)
	{
		int curgcd=a[i];
		int curlo=i;
		while(true)
		{
			int index=binsearch(i, curlo, n, curgcd);
			m[curgcd]+=(index-curlo+1);
			if(index==n)
				break;
			curlo=index+1;
			curgcd=query(i, curlo);
		}
	}
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	buildsparse();
	work();
	int q;
	cin>>q;
	while(q--)
	{
		int x;
		cin>>x;
		cout<<m[x]<<endl;
	}
	return 0;
}