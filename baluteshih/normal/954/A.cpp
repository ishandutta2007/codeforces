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

string s;

int main()
{
	int n,i,ans;
	cin >> n >> s,ans=n;
	for(i=0;i<n-1;++i)
		if(s[i]=='U' && s[i+1]=='R') --ans,++i;
		else if(s[i]=='R' && s[i+1]=='U') --ans,++i;
	cout << ans << "\n";
}