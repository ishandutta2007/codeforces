#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define ET cout << "\n"
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define DB(a,s,e) {for(int i=s;i<e;++i) cerr << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int arr[1000005],L[1000005],R[1000005];
vector<int> v;

bool yee(int a,int b)
{
	return a>b;
}

int main()
{jizz
	int n,x,l,r=0;
	ll ans=0;
	cin >> n >> x,l=n+1;
	for(int i=1;i<=n;++i)
	{
		cin >> arr[i];
		if(!L[arr[i]]) L[arr[i]]=i;
		R[arr[i]]=i;
	}
	v.pb(n+1);
	for(int i=x;i>1;--i)
		if(!L[i]) v.pb(v.back());
		else if(R[i]<l) l=L[i],v.pb(l);
		else break;
	ans+=v.size();
	
	for(int i=1;i<x;++i)
	{
		while(x-i+1<=v.size()) v.pop_back(); 
		if(!L[i])
		{
			int t=0,d=v.size()-1;
			while(t<d)
			{
				int m=(t+d)/2+1;
				if(r<v[m]) t=m;
				else d=m-1;
			}
			ans+=t+1;
		}
		else if(L[i]>r)
		{
			r=R[i];
			int t=0,d=v.size()-1;
			while(t<d)
			{
				int m=(t+d)/2+1;
				if(r<v[m]) t=m;
				else d=m-1;
			}
			ans+=t+1;
		}
		else break;
	}
	cout << ans << "\n";
}