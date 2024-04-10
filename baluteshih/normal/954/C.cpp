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

int arr[200000];

int ab(int x)
{
	return x<0 ? -x : x;
}

int main()
{
	int n,i,x,y=0;
	cin >> n;
	for(i=1,cin >> arr[0];i<n;++i)
	{
		cin >> arr[i];
		if(arr[i]==arr[i-1])
			return cout << "NO\n",0;
		if(ab(arr[i]-arr[i-1])!=1) y=ab(arr[i]-arr[i-1]);
	}
	if(y==0)
		return cout << "YES\n1 1000000000\n",0;
	for(i=1;i<n;++i)
	{
		if(ab(arr[i]-arr[i-1])!=1 && ab(arr[i]-arr[i-1])!=y) break;
		if(y && arr[i]-arr[i-1]==1 && arr[i]%y==1) break;
		if(y && arr[i]-arr[i-1]==-1 && arr[i]%y==0) break;
	}
	if(i<n) cout << "NO\n";
	else cout << "YES\n1000000000 " << y << "\n";
}