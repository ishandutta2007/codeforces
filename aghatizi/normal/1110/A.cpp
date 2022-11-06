#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e6 + 20;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int b , k;
	cin >> b >> k;
	b %= 2;

	int res = 0;
	for(int i = 1; i <= k; i++)
	{
		int x;
		cin >> x;
		x %= 2;

		if(b || i == k)
			res += x , res %= 2;
	}

	if(res)
		cout << "odd" << endl;
	else
		cout << "even" << endl;
}