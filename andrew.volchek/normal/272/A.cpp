#include <iostream>

using namespace std;


int main()
{
	int n;
	int s=0;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int a;
		cin >> a;
		s += a;
	}
	int ans = 0;
	for(int i=1;i<=5;i++)
	{
		if((s+i)%(n+1) != 1)
			ans++;
	}
	cout << ans;
	return 0;
}