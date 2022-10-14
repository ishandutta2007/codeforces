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
	int t;cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vi a(2*n);
		fi(2*n)
		{
			cin>>a[i];
		}	
		sortall(a);
		int fl=1;	
		fi(2*n-1)
		{
			if(a[i]!=a[i+1]||a[i]%2)
			{
				cout<<"NO"<<endl;
				fl=0;
				break;
			}
			i++;
		}
		if(fl)
		{
			vi arr;
			fi(2*n)
			{
				arr.pb(a[i]);
				i++;
			}
			if(arr[n-1]%(2*n))
			{
				cout<<"NO"<<endl;
				continue;
			}
			int mx=arr[n-1]/(n);
			int k=1;
			int fll=0;
			// deb(mx)
			set<int>b;
			b.insert(mx/2);
			for(int i=n-2;i>=0;i--)
			{
				arr[i]-=mx;
				if(arr[i]%(2*(n-k))||arr[i]<=0)
				{
					cout<<"NO"<<endl;
					fll=1;
					break;
				}
				int res=arr[i]/(2*(n-k));
				b.insert(res);
				k++;
				mx+=2*res;
				// deb(mx);
				// i++;
			}
			if(!fll){
				if(b.size()==n)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
			}
		}	
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