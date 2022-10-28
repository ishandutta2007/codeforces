#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define endl "\n"
#define int long long

const int N = 105;

int query(int x, int y)
{
	cout << "? " << x << " " << y << endl;
	int xx;
	cin >> xx;
	return xx;
}

vector<int> v = {4, 8, 15, 16, 23, 42};
map<vector<int>, vector<int> > ans;

int32_t main()
{
	IOS;
	do
	{
		vector<int> cur;
		for(int i = 0; i < 4; i++)
			cur.push_back(v[i] * v[i + 1]);
		ans[cur] = v;
	}while(next_permutation(v.begin(), v.end()));
	vector<int> reqd;
	for(int i = 1; i <= 4; i++)
		reqd.push_back(query(i, i + 1));
	cout << "! ";
	for(auto &it:ans[reqd])
		cout << it << " ";
	return 0;
}