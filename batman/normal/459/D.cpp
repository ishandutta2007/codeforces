//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.2.8 /////////////////
////////////////////////////////////////////////////////////////


// Yesterday is history...
// Tomorrow is a mystery...
// But Today is a GIFT.

#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cerr << #x << " is " << x << endl;
#define N (1001*1000)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define IB ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PI ((ld)3.1415926535897932384626433832795028841971)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)
#define HASH ((ll)1e16+7)
const ld sqr5=sqrt(5),p_=(1+sqr5)/2;
ll tavan(ll a,ll b){return b?(tavan(a*a,b>>1) * (b & 1?a:1)):1;}
ld fib(ll x){return (tavan(p_,x)-tavan(1-p_,x))/sqr5;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
bool isprime(ll x){for(ll i=2;i<=sqrt(x);i++)if(!(x%i))return false;return true;}
//bool sortt(ll x,ll y){ return a[x] < a[y]; }
ifstream fin("input.txt");
ofstream fout("output.txt");
ll n,a[N],ans;
map <ll,ll> mp;
ll l[N],tmp[N],r[N];
void merge_sort(ll left,ll right)
{
	if(left>=right-1)
		return;
	ll mid=(left+right)/2;	
	merge_sort(left,mid);
	merge_sort(mid,right);
	ll p1=left,p2=mid;
	for(int i=left;i<right && p1<mid && p2<right;i++)
	{
		if(l[p1]>r[p2])
			ans+=mid-p1,p2++;
		else
			p1++;	

	}
	p1=left,p2=mid;
	for(int i=left;i<right;i++)
	{
		if(p1<mid && (p2==right || l[p1]<l[p2]))
			tmp[i]=l[p1++];
		else
			tmp[i]=l[p2++];
	}
	for(int i=left;i<right;i++)
		l[i]=tmp[i];
	p1=left,p2=mid;
	for(int i=left;i<right;i++)
	{
		if((r[p1]<r[p2]  || p2==right) && p1<mid)
			tmp[i]=r[p1++];
		else
			tmp[i]=r[p2++];
	}
	
	for(int i=left;i<right;i++)
		r[i]=tmp[i];
	
}


int Sa1378
{
	IB
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		l[i]=(++mp[a[i]]);
	}
	mp.clear();
	for(int i=n-1;i>=0;i--)
		r[i]=(++mp[a[i]]);
	merge_sort(0,n);
	cout<<ans<<"\n";
	
	return 0;
}