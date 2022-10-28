#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;
 
int n;
int a[N];
vector<int> pos, neg, zero;
 
int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i] > 0)
			pos.push_back(a[i]);
		else if(a[i] < 0)
			neg.push_back(a[i]);
		else
			zero.push_back(a[i]);
	}
	cout << 1 << " " << neg[0] << endl;
	while(neg.size() > 2)
	{
		pos.push_back(neg.back());
		neg.pop_back();
		pos.push_back(neg.back());
		neg.pop_back();
	}
	cout << pos.size() << " ";
	for(auto &it:pos)
		cout << it << " ";
	cout << endl;
	cout << (neg.size() - 1 + zero.size()) << " ";
	for(int i = 1; i < neg.size(); i++)
		cout << neg[i] << " ";
	for(auto &it:zero)
		cout << it << " "; 
	return 0;
}