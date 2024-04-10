// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 


#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long int
#define ll long long int
#define fi(n) for(int i=0;i<n;i++)
#define fj(n) for(int j=0;j<n;j++)
#define W(x) int x;cin>>x;while(x--)
#define fr(n) for(int i=n-1;i>=0;i--)
#define mp make_pair
#define fo(i,a,n) for(int i=a;i<n;i++)
#define ps(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define vi vector<int>
#define deb(x) cout<<#x<<"="<<x<<endl;
#define all(a) (a).begin(),(a).end()
#define pii pair<int,int>
#define sortall(x) sort(all(x))
#define mk(arr,n,type)  type *arr=new type[n];
#define vpi vector<pair<int,int> >
#define setbits(x) __builtin_popcountll(x)
#define zerbits(x) __builtinctzll(x)
#define mod 1000000007
#define inf 1e18
#define sz(x) (int)x.size()
#define vs vector<string>
#define itr(a) for(auto it=a.begin();it!=a.end();it++)
#define f first
#define s second
#define INT_SIZE 32
int mpow(int exp, int base);
//I don't know what the funciton aeh() does but it speeds up my mess
void aeh()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
 
int32_t main()
{
	aeh();
	char a[4][4];
	fi(4)
	{
		fj(4)
		{
			cin>>a[i][j];
		}
	}
	string ans="NO";
	fi(4)
	{
		fj(2)
		{
			vector<char>b;
			for(int k=0;k<3;k++)
			{
				b.push_back(a[i][j+k]);
			}
			sortall(b);
			int x=0,z=0;
			for(int k=0;k<3;k++)
			{
				if(b[k]=='x')
					x++;
				else if(b[k]=='o')
					z++;
			}
			if(x==2&&z==0)
			{
				ans="YES";
				i=4;
				break;
			}
		}
	}
	fi(2)
	{
		fj(4)
		{
			vector<char>b;
			for(int k=0;k<3;k++)
			{
				b.push_back(a[i+k][j]);
			}
			sortall(b);
			int x=0,z=0;
			for(int k=0;k<3;k++)
			{
				if(b[k]=='x')
					x++;
				else if(b[k]=='o')
					z++;
			}
			if(x==2&&z==0)
			{
				ans="YES";
				i=4;
				break;
			}
		}
	}

	fi(2)
	{
		fj(2)
		{
			vector<char>b;
			for(int k=0;k<3;k++)
			{
				b.push_back(a[i+k][j+k]);
			}
			sortall(b);
			int x=0,z=0;
			for(int k=0;k<3;k++)
			{
				if(b[k]=='x')
					x++;
				else if(b[k]=='o')
					z++;
			}
			if(x==2&&z==0)
			{
				ans="YES";
				i=4;
				break;
			}
		}
	}


	for(int i=0;i<2;i++)
	{
		for(int j=2;j<4;j++)
		{
			vector<char>b;
			for(int k=0;k<3;k++)
			{
				b.push_back(a[i+k][j-k]);
			}
			sortall(b);
			int x=0,z=0;
			for(int k=0;k<3;k++)
			{
				if(b[k]=='x')
					x++;
				else if(b[k]=='o')
					z++;
			}
			if(x==2&&z==0)
			{
				ans="YES";
				i=4;
				break;
			}
		}
	}

	cout<<ans<<endl;
}

int mpow(int base, int exp)
{
	base %= mod;
	int result = 1;
	while (exp > 0)
	{
		if (exp & 1)result = (result * base) % mod;
		base = (base * base) % mod;
		exp >>= 1;
	}
	return result;
}