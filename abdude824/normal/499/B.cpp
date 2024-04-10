#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

#define fi(n) for(int i=0;i<n;i++)
#define fr(n) for(int i=n-1;i>=0;i--)
#define v(type) vector<type>
#define int long long
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define setbits(x) __builtin_popcountll(x)
#define zerbits(x) __builtinctzll(x)
#define mod 1000000007
#define inf 1e18
#define W(x) int x;cin>>x;while(x--)
#define ps(x,y) fixed<<setprecision(y)<<x

void aeh()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

int32_t main()
{
	aeh();
	int n,m;cin>>n>>m;
	v(string)a(m),b(m);
	fi(m)
	{
		cin>>a[i]>>b[i];
	}
	v(string)c(n);
	fi(n)
	{
		cin>>c[i];
	}
	fi(n)
	{
		int fl=0;
		for(int j=0;j<m;j++)
		{
			if(c[i]==a[j])
			{
				int x=a[j].size();
				int y=b[j].size();
				if(x>y)
					c[i]=b[j];
			}
			if(j==m-1)
				fl=1;
		}
		if(fl==0)
		{
			for(int j=0;j<m;j++)
			{
				if(c[i]==b[j])
				{
					int x=a[j].size();
					int y=b[j].size();
					if(x<=y)
						c[i]=a[j];

				}
			}
		}
	}
	fi(n)
	{
		cout<<c[i]<<" ";
	}
	cout<<endl;
}