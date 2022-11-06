#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int x = 0 , y = 0;
	vector<pair<int , int> > points;
	points.pb(make_pair(x , y));

	n -= 2;
	while(n--)
	{
		if(x == 6 && y == 5 && n > 0)
		{
			points.pb(make_pair(6 , 7));
			points.pb(make_pair(6 , 6));
			n--;

			x = 6 , y = 6;

			if(n > 0)
			{
				points.pb(make_pair(7 , 6));
				n--;
				x = 7 , y = 6;
			}

			continue;
		}

		if(x % 2 == 0)
		{
			if(y == 8 - 1)
				x++;
			else
				y++;
		}
		else
		{
			if(y == 0)
				x++;
			else
				y--;
		}

		points.pb(make_pair(x , y));
	}

	if(points.back().first == 8 - 1)
	{
		points.pb(make_pair(8 - 1 , 0));
		points.pb(make_pair(8 - 1 , 8 - 1));
	}
	else if(points.back().second == 8 - 1)
	{
		points.pb(make_pair(8 - 2 , 8 - 1));
		points.pb(make_pair(8 - 1 , 8 - 1));
	}
	else
	{
		points.pb(make_pair(8 - 1 , points.back().second));
		points.pb(make_pair(8 - 1 , 8 - 1));
	}

	for(auto x : points)
		cout << (char)(x.second + 'a') << x.first + 1 << " ";
	cout << endl;
}