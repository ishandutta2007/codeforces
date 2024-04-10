#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define MP make_pair
#define ET cout << "\n"
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll arr[1000000],L[1000000],R[1000000],st[1000000],k;
const ll MOD=1e9+7;

inline ll f(ll L)
{
	ll t=L/k;
	if(t==0) return 0;
	if(L%k==0) --t; 
	if(t==0) return 0;
	//cout << "f(" << L << ") = " << t*L-k*(t+1)*t/2 << "\n";
	return t*L-k*(t+1)*t/2;
}

int main()
{jizz
	ll n,top,l,r,ans=0,tmp;
	cin >> n >> k,--k;
	for(int i=0;i<n;++i)
		cin >> arr[i];
	top=-1;
	for(int i=0;i<n;++i)
	{
		while(top>-1 && arr[i]>=arr[st[top]]) --top;
		if(top>-1) L[i]=st[top]+1;
		else L[i]=0;
		st[++top]=i;
	}
	top=-1;
	for(int i=n-1;i>=0;--i)
	{
		while(top>-1 && arr[i]>arr[st[top]]) --top;
		if(top>-1) R[i]=st[top]-1;
		else R[i]=n-1;
		st[++top]=i;
	}
	for(int i=0;i<n;++i)
	{
		tmp=ans;
		ans=(ans+f(R[i]-L[i]+1)%MOD*arr[i])%MOD;
		ans=(ans-f(i-L[i])%MOD*arr[i]%MOD+MOD)%MOD;
		ans=(ans-f(R[i]-i)%MOD*arr[i]%MOD+MOD)%MOD;	
		//cout << R[i]-L[i]+1 << " - " << i-L[i] << " - " << R[i]-i << " = " << ans-tmp << "\n";
	}
	cout << ans << "\n";
}