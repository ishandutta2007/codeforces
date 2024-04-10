#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int32_t main()
{
	IOS;
	string a, b;
	cin>>a>>b;
	int cta=0, ctb=0;
	for(auto &it:a)
		cta+=(it=='1');
	for(auto &it:b)
		ctb+=(it=='1');
	cta=(cta>0);
	ctb=(ctb>0);
	if(cta==ctb && a.size()==b.size())
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}