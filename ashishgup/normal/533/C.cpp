#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int32_t main()
{
	IOS;
	int x1, y1, x2, y2;
	cin>>x1>>y1>>x2>>y2;
	int win=0;
	win|=(x1<=x2 && y1<=y2);
	win|=(x1+y1 <= max(x2, y2));
	if(win)
		cout<<"Polycarp";
	else
		cout<<"Vasiliy";
	return 0;
}