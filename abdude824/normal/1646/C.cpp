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
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
}
struct Contri{
	string nam;
	vector<pair<int,string>>skill;
};
struct Proj{
	string nam;
	int d,s,b;
	vector<pair<int,string>> role;
};
int fact(int x)
{
	int ans=1;
	fi(x)ans*=(i+1);
	return ans;
}
int fn(int curr,int i,vi &a,int cnt=0ll)
{
	if(i>=a.size())return setbits(curr)+cnt;
	int x=curr-a[i];
	if(x<0)return setbits(curr)+cnt;
	int b=setbits(x)+cnt+1ll;
	int c=fn(x,i+1ll,a,cnt+1ll);
	int d=setbits(fn(curr,i+1ll,a,cnt))+cnt;
	int e=setbits(curr)+cnt;
	return min({b,c,d,e});
}
void subsetSums(vpi &g,vi arr, int l, int r,int cnt=0, int sum = 0)
{
    // Print current subset
    if (l > r) {
    	g.pb({sum,cnt});	
        return;
    }
 
    // Subset including arr[l]
    subsetSums(g,arr, l + 1ll, r, cnt+1,sum + arr[l]);
 
    // Subset excluding arr[l]
    subsetSums(g,arr, l + 1ll, r, cnt,sum);
}
int32_t main()
{
	aeh();
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
		vector<int>a;
		fi(15)a.push_back(fact(i));
		vpi g;
		subsetSums(g,a,0,a.size());
		int ans=setbits(n);
		fi(g.size())
		{
			if(n-g[i].first>=0){
				int x=setbits(n-g[i].first)+g[i].second;
				// deb(g[i].first)
				// deb(g[i].second)
				// deb(x)
				ans=min(ans,x);
			}
		}
		cout<<ans<<endl;
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