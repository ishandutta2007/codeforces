#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <math.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

int main()
{
	long long n,tmp,ans=-10000000,x;
	cin >> n;
	while(n--)
	{
		cin >> tmp;
		if(tmp>=0)
		{
			x=sqrt(tmp);
			if(x*x!=tmp) ans=max(tmp,ans);
		}
		else ans=max(tmp,ans);
	}
	cout << ans << "\n";
}