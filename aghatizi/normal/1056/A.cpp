#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

int t[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		int k;
		cin >> k;

		while(k--)
		{
			int x;
			cin >> x;

			t[x]++;
		}
	}

	for(int i = 0; i < maxn; i++)
		if(t[i] == n)
			cout << i << " ";
	cout << endl;
}