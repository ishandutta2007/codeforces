#include <bits/stdc++.h>

using namespace std;

int n;
int ans;

int f(int i, int j)
{
	return (i + j) % (n + 1);
}

int main()
{
	cin >> n;
	int l = 1, r = n;
	for(int i = 1; i < n; i++)
	{
		ans += f(l, r);
		if(i % 2) l++;
		else r--;
	}
	cout << ans;
}