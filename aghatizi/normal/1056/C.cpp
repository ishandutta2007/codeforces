#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

pair<int , int> a[maxn];

int from[maxn] , to[maxn];

bool is[maxn] , shit[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , m;
	cin >> n >> m;

	n *= 2;
	for(int i = 0; i < n; i++)
		cin >> a[i].first , a[i].second = i;

	for(int i = 0; i < m; i++)
	{
		int a , b;
		cin >> a >> b;
		a-- , b--;

		from[i] = a , to[i] = b;
		is[a] = is[b] = 1;
	}

	int turn;
	cin >> turn;

	for(int i = 0; i < m; i++)
		if(a[from[i]].first < a[to[i]].first)
			swap(from[i] , to[i]);

	sort(a , a + n);

	int rem = n;
	if(turn == 2)
	{
		while(rem > 0)
		{
			int x;
			cin >> x;
			x--;

			shit[x] = 1;
			rem--;

			if(!is[x])
				break;
			else
			{
				for(int i = 0; i < m; i++)
					if(from[i] == x || to[i] == x)
					{
						cout << (from[i] ^ to[i] ^ x) + 1 << endl;
						shit[from[i]^to[i]^x] = 1;
					}
			}

			rem--;
		}
	}

	for(int i = 0; i < m; i++)
	{
		if(shit[from[i]])
			continue;

		cout << from[i] + 1 << endl;
		rem--;

		if(rem)
		{
			int x;
			cin >> x;

			shit[from[i]] = shit[to[i]] = 1;
			assert(x == to[i] + 1);
			rem--;
		}
	}

	for(int i = n - 1; i >= 0; i--)
		if(!shit[a[i].second])
		{
			cout << a[i].second + 1 << endl;
			rem--;

			if(rem)
			{
				int x;
				cin >> x;
				x--;

				shit[x] = 1;
				rem--;
			}
		}
}