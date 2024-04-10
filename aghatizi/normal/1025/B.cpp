#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 15e4 + 20;

int a[maxn] , b[maxn];

bool check(int x , int n)
{
	for(int i = 0; i < n; i++)
		if(a[i] % x != 0 && b[i] % x != 0)
			return 0;

	return 1;
}

void handle(int x , int n)
{
	for(int i = 2; i * i <= x; i++)
		if(x % i == 0)
		{
			while(x % i == 0)
				x /= i;

			if(check(i , n))
			{
				cout << i << endl;
				exit(0);
			}
		}

	if(x > 1 && check(x , n))
	{
		cout << x << endl;
		exit(0);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int mn = 2e9 + 10;

	for(int i = 0; i < n; i++)
		cin >> a[i] >> b[i] , mn = min(mn , min(a[i] , b[i]));

	handle(a[0] , n);
	handle(b[0] , n);

	cout << -1 << endl;
}