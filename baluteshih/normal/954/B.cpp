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
	int n,i,j,k;
	cin >> n >> s;
	if(n==1)
		return cout << "1\n",0;
	for(i=n/2*2;i>=4;i-=2)
	{
		for(k=0;k+i/2<i;++k)
			if(s[k]!=s[k+i/2]) break;
		if(k+i/2==i) break; 
	}
	cout << n-i/2+1 << "\n";
	
}