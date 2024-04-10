#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n;
string a, b;
vector<int> v;

char flip(char ch)
{
	if(ch == '0')
		return '1';
	return '0';
}

void perform(int idx)
{
	if(flip(a[0]) != b[idx])
	{
		v.push_back(0);
		a[0] = flip(a[0]);
	}
	if(a[idx] == b[idx])
		return;
	v.push_back(idx);
	for(int j = 0; j <= idx; j++)
		a[j] = flip(a[j]);
	reverse(a.begin(), a.begin() + idx + 1);
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		v.clear();
		cin >> n;
		cin >> a >> b;
		for(int i = n - 1; i >= 0; i--)
		{
			while(a[i] != b[i])
				perform(i);
		}
		cout << v.size() << " ";
		for(auto &it:v)
			cout << it + 1 << " ";
		cout << endl;
	}
	return 0;
}