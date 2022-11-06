#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

bool f = 0;

int C = 0 , D = 0;

int get(int c , int d)
{
	cout << "? " << c << " " << d << endl;
	int x;
	cin >> x;

	if(x == 2)
		cout << 1/0;

	return x;
}

int print(int c , int d)
{
	c ^= C;
	d ^= D;
	if(f)
		swap(c , d);

	return get(c , d) * (f? -1 : 1);
}

int A , B;

vector<int> un;

void solve(int k)
{
	bool shit = 0;
	for(int i = k - 1; i >= 0; i--)
	{
		if(!shit)
		{
			int x = print(0 , 0);

			if(x == 0)
			{
				for(int j = 0; j <= i; j++)
					un.pb(j);
				return;
			}
			if(x < 0)
				f ^= 1 , swap(C , D) , swap(A , B);

			shit = 1;
		}

		int tmp = print(1 << i , 1 << i);

		if(tmp < 0)
		{
			A ^= (1 << i);
			C ^= (1 << i);
			shit = 0;
		}
		if(tmp == 0)
			cout << 1/0;
		if(tmp > 0)
			un.pb(i);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solve(30);
	
	for(auto x : un)
	{
		int tmp = print(1 << x , 0);

		if(tmp == 0)
			cout << 1/0;
		if(tmp < 0)
			A ^= (1 << x) , B ^= (1 << x);
	}

	if(f)
		swap(A , B);

	cout << "! " << A << " " << B << endl;
}