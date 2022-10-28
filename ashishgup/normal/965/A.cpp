#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int k, n, s, p;

int32_t main()
{
	IOS;
	cin>>k>>n>>s>>p;
	int sheets=n/s;
	if(n%s)
		sheets++;
	int tot=sheets*k;
	int packs=tot/p;
	if(tot%p)
		packs++;
	cout<<packs;
}