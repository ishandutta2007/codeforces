#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, m, a, b;

int32_t main()

{
	IOS;
	cin>>n>>m>>a>>b;
	int r1=(a-1)/m, r2=(b-1)/m;
	int c1=(a-1)%m + 1;
	int c2=(b-1)%m + 1;
	if(r1==r2)
		cout<<"1";
	else if(c1==1 && (c2==m||b==n))
		cout<<"1";
	else if(c1==1 || (c2==m||b==n))
		cout<<"2";
	else if(r2-r1==1)
		cout<<"2";
	else if(c1 == c2+1)
		cout<<"2";
	else
		cout<<"3";
	return 0;
}