#include<bits/stdc++.h>

using namespace std;

#define fi(n) for(int i=0;i<n;i++)
#define fj(n) for(int j=0;j<n;j++)
#define fr(n) for(int i=n-1;i>=0;i--)
#define fo(i,a,n) for(int i=a;i<n;i++)
#define vi vector<int>
#define vs vector<string>
#define vpi vector<pair<int,int> >
#define int long long int
#define all(a) (a).begin(),(a).end()
#define sortall(x) sort(all(x))
#define itr(a) for(auto it=a.begin();it!=a.end();it++)
#define pb push_back
#define setbits(x) __builtin_popcountll(x)
#define zerbits(x) __builtinctzll(x)
#define mod 1000000007
#define sz(x) (int)x.size()
#define inf 1e18
#define W(x) int x;cin>>x;while(x--)
#define ps(x,y) fixed<<setprecision(y)<<x
#define mp make_pair
#define INT_SIZE 32
#define pr pair<int,int>
#define deb(x) cout<<#x<<"="<<x<<endl;
#define F first
#define S second
#define pii pair<int,int>
#define mk(arr,n,type)  type *arr=new type[n];

int mpow(int exp, int base);
void aeh()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int arr[8001], is[8001]; //is will tell if ith number is special or not
int32_t main()
{
	aeh();
	W(t)
	{
		//we need to find a[i] such that a[i]=sum(a[l],a[r])
		//prefix sum array would contain sum(a[l])and sum(a[r])
		//any two values when subtracted(Suppose l-1 and r) then the result
		//would be sum(a[l],a[r])
		// this sum if present in a, then cnt++;


		int n;
		cin >> n;
		fi(n) {
			cin >> arr[i];
			is[i + 1] = 0;
		}
		for (int i = 0; i < n; i++)
		{
			int sum = arr[i];
			for (int j = i + 1; j < n; j++)
			{
				sum += arr[j];
				if (sum > n)
					break;
				is[sum] = 1;
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			if (is[arr[i]])
				ans++;
		}
		cout << ans << endl;
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