#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;

int a[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , m;
	cin >> n >> m;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	int last = m;

	for(int i = 0; i < n; i++)
	{
		int turn = 0;
		if(a[i] < last)
		{
			turn = 0;
			last -= a[i];
		}
		else
		{
			a[i] -= last;
			last = m;
			turn++;

				turn += a[i] / m;
				last = m - (a[i] % m);
		}

		cout << turn << " ";
	}
	cout << endl;
}