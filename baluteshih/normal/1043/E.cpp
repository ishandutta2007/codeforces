#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MP make_pair
#define ET cout << "\n"
#define ALL(v) v.begin(),v.end()
#define MEM(i,j) memset(i,j,sizeof i)
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

pll arr[300000],so[300000];
ll ans[300000];

int main()
{jizz
	ll n,m,a=0,b=0;
	cin >> n >> m;
	for(int i=0;i<n;++i)
		cin >> arr[i].F >> arr[i].S,so[i]=MP(arr[i].F-arr[i].S,i),a+=arr[i].S;
	sort(so,so+n);
	for(int i=0;i<n;++i)
	{
		a-=arr[so[i].S].S;
		ans[so[i].S]=a+b+arr[so[i].S].F*(n-i-1)+arr[so[i].S].S*i;
		b+=arr[so[i].S].F;
	}
	while(m--)
	{
		cin >> a >> b,--a,--b;
		if(arr[a].F+arr[b].S<arr[a].S+arr[b].F)
			ans[a]-=arr[a].F+arr[b].S,ans[b]-=arr[a].F+arr[b].S;
		else  
			ans[a]-=arr[a].S+arr[b].F,ans[b]-=arr[a].S+arr[b].F;
	}
	for(int i=0;i<n;++i)
		cout << ans[i] << " ";
	ET;
}