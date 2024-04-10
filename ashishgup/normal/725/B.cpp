#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int32_t main()
{
	IOS;
	map<char, int> m;
	m['f']=1;
	m['e']=2;
	m['d']=3;
	m['a']=4;
	m['b']=5;
	m['c']=6;
	string s;
	cin>>s;
	int n;
	char ch;
	stringstream ss(s);
	ss>>n>>ch;
	int prev=(n-1)/4;
	int ans=16*prev;
	if(n%4==1 || n%4==3)
		ans+=m[ch];
	else
		ans+=7+m[ch];
	cout<<ans;
	return 0;
}