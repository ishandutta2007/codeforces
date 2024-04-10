#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	int n;
	cin>>n;
	int feet=n/36;
	n%=36;
	int inches=n/3;
	n%=3;
	if(n>1)
		inches++;
	if(inches==12)
		feet++, inches=0;
	cout<<feet<<" "<<inches;
	return 0;
}