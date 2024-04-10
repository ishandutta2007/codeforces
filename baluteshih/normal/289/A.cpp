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

int main()
{
	ll n,ans=0,l,r,k;
	cin >> n >> k;
	while(n--)
		cin >> l >> r,ans+=r-l+1;
	cout << (k-ans%k)%k << "\n";
}