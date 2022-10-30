#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	pair < int, int > a[50];

	for(int i=0;i<n;i++)
	{
		cin >> a[i].first >> a[i].second;
	}

	long ans = 0;

	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i].first == a[j].second)
				ans++;
			if(a[i].second == a[j].first)
				ans++;
		}
	}

	cout << ans;

	return 0;
}