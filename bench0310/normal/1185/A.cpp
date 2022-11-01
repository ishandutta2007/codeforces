#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector<long long> v(3);
	for(int i=0;i<3;i++) cin >> v[i];
	long long d;
	cin >> d;
	sort(v.begin(),v.end());
	cout << max(0ll,d-(v[1]-v[0]))+max(0ll,d-(v[2]-v[1])) << endl;
	return 0;
}