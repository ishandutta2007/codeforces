#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;
 
int p, k;
vector<int> poly;
 
int32_t main()
{
	IOS;
	cin >> p >> k;
	while(abs(p) > 0)
	{
		int rem = (p % k + k) % k;
		poly.push_back(rem);
		p -= rem;
		p /= (-k);
	}
	cout << poly.size() << endl;
	for(auto &it:poly)
		cout << it << " ";
	return 0;
}