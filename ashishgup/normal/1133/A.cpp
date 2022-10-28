#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	string a, b;
	cin>>a>>b;
	stringstream ss(a);
	int hh, mm, hh2, mm2;
	char ch;
	ss>>hh>>ch>>mm;
	stringstream ss2(b);
	ss2>>hh2>>ch>>mm2;
	int first = hh * 60 + mm;
	int second = hh2 * 60 + mm2;
	int mid = (first + second)/2;
	int hours = mid/60;
	int min = mid%60; 
	cout<<setfill('0')<<setw(2)<<hours;
	cout<<":";
	cout<<setfill('0')<<setw(2)<<min;
	return 0;
}