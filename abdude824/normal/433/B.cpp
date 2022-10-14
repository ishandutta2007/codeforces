#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

#define fi(n) for(int i=0;i<n;i++)
#define fr(n) for(int i=n-1;i>=0;i--)
#define vi vector<int>
#define vs vector<string>
#define int long long int
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define setbits(x) __builtin_popcountll(x)
#define zerbits(x) __builtinctzll(x)
#define mod 1000000007
#define inf 1e18
#define W(x) int x;cin>>x;while(x--)
#define ps(x,y) fixed<<setprecision(y)<<x
#define mp make_pair
void aeh()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("aana.txt", "r", stdin);
		freopen("jaana.txt", "w", stdout);
	#endif
}
int gcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	int d=gcd(b,a%b,x,y);
	int t=x;
	x=y;
	y=t-y*(a/b);
	return d;
}

int32_t main() {
	aeh();
	int n;cin>>n;
	vi a(n),b(n+1),c(n+1),d(n);

	fi(n)
	cin>>a[i];
	b[0]=0;

	fi(n)
	{
		d[i]=a[i];
	}
	sort(d.begin(),d.end());
	for(int i=0;i<n;i++)
	{
		b[i+1]=b[i]+a[i];
		c[i+1]=c[i]+d[i];
	}
	int m;cin>>m;
	while(m--)
	{
		int ty;cin>>ty;
		int l,r;cin>>l>>r;
		if(ty==1)
		{
			cout<<b[r]-b[l-1]<<endl;
		}
		if(ty==2)
		{
			cout<<c[r]-c[l-1]<<endl;
		}

	}
}