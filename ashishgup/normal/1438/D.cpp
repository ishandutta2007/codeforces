#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;

int n, even;
int a[N];
vector<int> u, v, w;

void forward(int x)
{
	u.push_back(x);
	v.push_back(x + 1);
	w.push_back(x + 2);
	int val = a[x] ^ a[x + 1] ^ a[x + 2];
	a[x] = a[x + 1] = a[x + 2] = val;
}

void last(int x)
{
	u.push_back(x);
	v.push_back(x + 1);
	w.push_back(n - even);
	int val = a[x] ^ a[x + 1] ^ a[n - even];
	a[x] = a[x + 1] = a[n - even] = val;
}

int32_t main()
{
	IOS;
	u.clear(), v.clear(), w.clear();
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	even = (n % 2 == 0);
	for(int i = 1;  i + 2 <= n - even; i += 2)
		forward(i);
	for(int i = 1; i + 2 <= n - even; i += 2)
		last(i);
	int flag = 1;
	for(int i = 1; i + 1 <= n; i++)
		flag &= (a[i] == a[i + 1]);
	if(flag)
	{
		cout << "YES" << endl;
		cout << u.size() << endl;
		for(int i = 0; i < u.size(); i++)
			cout << u[i] << " " << v[i] << " " << w[i] << endl;
	}
	else
		cout << "NO" << endl;
	return 0;
}