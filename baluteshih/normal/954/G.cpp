#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define pb push_back
#define F first
#define S second
#define MEM(i,j) memset(i,j,sizeof i);
#define ET cout << "\n";
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET}
using namespace std;

ll num[500005],tnum[500005],n,r;

bool check(ll x,ll K)
{
	ll i,j,k,tmp=0;
	for(i=1;i<=n;++i) tnum[i]=num[i];
	for(i=j=k=1;i<=n;++i)
	{
		while(j<=i+r && j<=n) tmp+=tnum[j],++j;
		while(k<i-r) tmp-=tnum[k],++k;
		if(tmp<x) K-=x-tmp,tnum[min(i+r,n)]+=x-tmp,tmp=x;
		if(K<0) break;
	}
	return K>=0;
}

int main()
{jizz
	ll k,i,L=0,R=0,m;
	cin >> n >> r >> k,R=k+1;
	for(i=1;i<=n;++i)
		cin >> num[i],R+=num[i];
	while(L<R)
	{
		ll m=(L+R)/2+1;
		if(check(m,k)) L=m;
		else R=m-1;
	}
	cout << L << "\n";
}