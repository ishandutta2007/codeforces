#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define int ll

const int maxn = 1e5 + 20;

bool is[maxn];

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a , b;
	cin >> a >> b;

	ll s = (a + b);
	int k = 0;

	for(int i = 1; i <= s; i++)
	{
		s -= i;
		k = i;
	}

	vector<int> A , B;
	for(int i = k; i >= 1; i--)
	{
		if(a >= i)
		{
			a -= i;
			A.pb(i);
			is[i] = 1;
		}
	}

	for(int i = 1; i <= k; i++)
		if(!is[i] && b >= i)
		{
			B.pb(i);
			b -= i;
		}

	cout << A.size() << endl;
	for(auto x : A)
		cout << x << " ";
	cout << endl;

	cout << B.size() << endl;
	for(auto x : B)
		cout << x << " ";
	cout << endl;
}