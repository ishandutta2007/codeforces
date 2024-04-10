#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

void rec(int a, int b)
{
	if(a==0)
	{
		cout<<a<<" "<<b;
		exit(0);
	}
	if(b==0)
	{
		cout<<a<<" "<<b;
		exit(0);
	}
	if(a>=2*b)
		return rec(a%(2*b), b);
	if(b>=2*a)
		return rec(a, b%(2*a));
	cout<<a<<" "<<b;
	exit(0);
}

int32_t main()
{
    IOS;
    int a, b;
    cin>>a>>b;
    rec(a, b);
    return 0;
}