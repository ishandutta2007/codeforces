#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e3 + 20;

int x[3] , y[3];

bool visited[maxn][maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for(int i = 0; i < 3; i++)
		cin >> x[i] >> y[i];

	pair<int , pair<int , int> > res = {1e9 , {0 , 0}};
	for(int i = -1000; i < 2000; i++)
		for(int j = -1000; j < 2000; j++)
		{
			int s = 0;
			for(int k = 0; k < 3; k++)
				s += abs(i - x[k]) + abs(j - y[k]);

			res = min(res , make_pair(s + 1 , make_pair(i , j)));
		}

	cout << res.first << endl;
	int X = res.second.first , Y = res.second.second;

	for(int i = 0; i < 3; i++)
	{
		int tx = X , ty = Y;

		while(tx != x[i])
		{
			if(tx > x[i])
				tx--;
			else
				tx++;

			cout << tx << " " << ty << endl;
		}

		while(ty != y[i])
		{
			if(ty > y[i])
				ty--;
			else
				ty++;

			cout << tx << " " << ty << endl;
		}
	}

	cout << X << " " << Y << endl;
}