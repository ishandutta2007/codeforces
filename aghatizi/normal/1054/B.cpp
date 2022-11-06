#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

int mex , is[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;

		if(x >= maxn || x > mex)
			return cout << i + 1 << endl , 0;

		is[x] = 1;

		while(is[mex])
			mex++;
	}

	cout << -1 << endl;

}