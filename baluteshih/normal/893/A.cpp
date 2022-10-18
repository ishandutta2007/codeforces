#include <iostream>
#define __ ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

int main()
{
	int n,a,now,out;
	cin >> n,now=3,out=3;
	while(n--)
	{
		cin >> a;
		if(a==out) 
		{
			puts("NO");
			return 0;
		}
		out=now-a,now=6-out;
	}
	puts("YES");
}