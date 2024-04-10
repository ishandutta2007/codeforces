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
bool nice(set<int>&a)
{
	vi b;
	for(auto it:a)
		b.pb(it);
	int n=b.size();
	fi(b.size())
	{
		fj(b.size())
		{
			if(i!=j)
			{
				if(a.find(abs(b[i]-b[j]))==a.end())
				{
					a.insert(abs(b[i]-b[j]));
					b.pb(abs(b[i]-b[j]));
				}
				if(a.size()>300)return 0;
			}
		}
	}
	return 1;
}
int32_t main()
{
	aeh();
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
		set<int>a;
		vi b;
		fi(n)
		{
			int x;
			cin>>x;		
			b.pb(x);
			a.insert(x);
		}
		if(a.size()<n)
			cout<<"NO\n";
		else{
			int fl=0;
			// while(true)
			// {
				if(!nice(a))
				{
					cout<<"NO\n";
					fl=1;
				}
			// }
			if(!fl){
				cout<<"YES\n";
				cout<<a.size()<<"\n";
				for(auto it:a)
					cout<<it<<" ";
				cout<<"\n";
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