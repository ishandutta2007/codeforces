#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	int n;
	string a , b;
	cin >> n >> a >> b;

	int res = 0 , last = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] == b[i])
			res += last , last = 0;
		else if(a[i] != a[i - 1])
		{
			if(last)
				res++ , last = 0;
			else
				last = 1;
		}
		else
			res += last , last = 1;
	}

	res += last;

	cout << res << endl;



}