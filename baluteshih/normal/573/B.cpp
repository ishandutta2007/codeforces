#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define pb push_back
#define F first
#define S second
#define MEM(i,j) memset(i,j,sizeof i)
#define ET cout << "\n"
#define MP make_pair
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;

int num[100000],l[100000],r[100000];

int main()
{jizz
	int n,i,ans=0;
	cin >> n;
	for(i=0;i<n;++i)
		cin >> num[i];
	for(i=1,l[0]=1;i<n;++i)
		l[i]=min({l[i-1]+1,num[i],i+1});
	for(i=n-2,r[n-1]=1;i>=0;--i)
		r[i]=min({r[i+1]+1,num[i],n-i});
	for(i=0;i<n;++i)
		ans=max(ans,min(l[i],r[i]));
	cout << ans << "\n";
}