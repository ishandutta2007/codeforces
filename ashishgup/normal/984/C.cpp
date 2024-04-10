#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

bool isDivisible(int x, int y)
{	
    if (y == 1)
        return true;
 	int storegcd=__gcd(x, y);
    if (storegcd == 1)
        return false;
    return isDivisible(storegcd, y / storegcd);
}

int32_t main()
{
	IOS;
	int q;
	cin>>q;
	while(q--)
	{
		int p, q, b;
		cin>>p>>q>>b;
		if(p==0)
		{
			cout<<"Finite"<<endl;
			continue;
		}
		int storegcd=__gcd(p, q);
		q/=storegcd;
		if(isDivisible(b, q))
		{
			cout<<"Finite"<<endl;
		}
		else
		{
			cout<<"Infinite"<<endl;
		}
	}
	return 0;
}