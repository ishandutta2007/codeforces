#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e6+10;

int t, store=0, missing, largest;
int a[N], f[N], curf[N];

void check(int n, int m)
{
	//x + y = largest + 2
	//x = n + 1 - missing or y = m + 1 - missing

	memset(curf, 0, sizeof(curf));

	int x=n+1-missing, y=largest+2-x;

	if(x>=1 && x<=n && y>=1 && y<=m)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				curf[abs(i-x) + abs(j-y)]++;
			}
		}
		int check=1;
		for(int i=0;i<=t;i++)
		{
			check&=(curf[i]==f[i]);
		}
		if(check)
		{
			cout<<n<<" "<<m<<endl;
			cout<<x<<" "<<y;
			exit(0);
		}
	}
	
	memset(curf, 0, sizeof(curf));

	y=m+1-missing, x=largest+2-y;

	if(x>=1 && x<=n && y>=1 && y<=m)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				curf[abs(i-x) + abs(j-y)]++;
			}
		}
		int check=1;
		for(int i=0;i<=t;i++)
		{
			check&=(curf[i]==f[i]);
		}
		if(check)
		{
			cout<<n<<" "<<m<<endl;
			cout<<x<<" "<<y;
			exit(0);
		}
	}
}

int32_t main()
{
	IOS;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>a[i];
		f[a[i]]++;
	}
	if(!f[0])
	{
		cout<<"-1";
		return 0;
	}
	for(int i=0;i<=t;i++)
	{
		if(f[i])
			largest=i;
		if(f[i]<4*i && missing==0)
			missing=i;
		if(i>=1 && f[i]>4*i)
		{
			cout<<"-1";
			return 0;
		}
	}
	for(int i=1;i*i<=t;i++)
	{
		if(t%i==0)
			check(i, t/i);
	}
	cout<<"-1";
	return 0;
}