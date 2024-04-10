#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, i, a[110], one=0, sec=0;
	set<int> s;
	cin>>n;
	for(i=0;i<n/2;i++)
	{
		cin>>a[i];
		
	}
	sort(a, a+ n/2);

	for(i=1;i<=n/2;i++)
	{
		if(a[i-1] != 2*i) one+=abs(2*i - a[i-1]);
		if(a[i-1] != (2*i-1)) sec+=abs((2*i-1) - a[i-1]);
	}

	cout << min(one, sec) <<"\n";
	return 0;
}