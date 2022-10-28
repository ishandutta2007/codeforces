#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, long long m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }
 
const int N=1e6+5;
const int MOD=1e9+7;

int n;
int a[N], fact[N], invfact[N];
map<int, int> m;
vector<pair<int, int> > v;

int modinv(int k)
{
	return pow(k, MOD-2, MOD);
}

void precompute()
{
	fact[0]=fact[1]=1;
	invfact[0]=invfact[1]=1;
	for(int i=2;i<N;i++)
	{
		fact[i]=fact[i-1]*i;
		fact[i]%=MOD;
		invfact[i]=modinv(fact[i]);
	}
}

int32_t main()
{
    IOS;
    precompute();
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	m[a[i]]++;
    }
    for(auto it:m)
    	v.push_back(it);
    v.pop_back();
    int ans=0;
    int smaller=0;
    for(int i=0;i<v.size();i++)
    {
    	//Probability logic: The probability of atleast one of the occurences of current element (u) being present before all the larger elements (v) = u/(u+v)
    	int probability=v[i].second;
    	probability*=modinv(n-smaller);
    	probability%=MOD;
    	int contribution=fact[n] * v[i].first;
    	contribution%=MOD;
    	int temp=probability*contribution;
    	temp%=MOD;
    	smaller+=v[i].second;
    	ans+=temp;
    	ans%=MOD;
    }
    cout<<ans;
    return 0;
}