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
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
		vi a(n);
		fi(n)cin>>a[i];
		vi b(n);
		fi(n)cin>>b[i];
		int x=n-(n/4);
		vi a1(101);
		vi b1(101);
		fi(n)a1[a[i]]++;
		fi(n)b1[b[i]]++;
		int i=0;
		while(i<=n)
		{
			int s1=0;
			int x1=n+i;
			x1=x1-(x1/4);
			for(int j=100;j>=0&&x1>0;j--)
			{
				if(a1[j]){
					int c=a1[j]<=x1?a1[j]:x1;
					s1+=(c*j);
					x1-=c;
				}
			}
			int s2=0;
			x1=n+i;
			x1=x1-(x1/4);
			for(int j=100;j>=0&&x1>0;j--)
			{
				if(b1[j]){
					int c=b1[j]<=x1?b1[j]:x1;
					s2+=(c*j);
					x1-=c;
				}
			}			
			// deb(s1)
			// deb(s2)
			if(s1>=s2)
				break;
			a1[100]++;
			i++;

		}
		cout<<i<<endl;
	}
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