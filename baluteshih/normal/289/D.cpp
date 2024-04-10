#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define pb push_back
#define MEM(i,j) memset(i,j,sizeof i)
#define F first
#define S second
#define ET cout << "\n"
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;

const ll MOD=1e9+7;

ll pow(ll a,ll n)
{
	ll re=1;
	for(;n;n/=2,a=a*a%MOD)
		if(n&1) re=re*a%MOD;
	return re;
}

int main()
{
	ll n,k,ans=1,a[9]={0,1,2,9,64,625,7776,117649,2097152};
	cin >> n >> k,ans=pow(n-k,n-k);
	cout << a[k]*ans%MOD << "\n";
}