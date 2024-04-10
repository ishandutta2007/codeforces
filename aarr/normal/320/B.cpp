#include <iostream>

#include <vector>

using namespace std;
pair<int, int> dots[105];
int path[105][105];
vector<int> v;
vector<int> u;
int main()
{
	int n, ndots = 0;
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		int x, y, z;
		cin >> x;
		cin >> y;
		cin >> z;
		if(x == 1)
		{
			for(int j = 0; j < ndots; j ++)
			{
				if((dots[j].first < y && y < dots[j].second) || (dots[j].first < z && z < dots[j].second))
				{
					u.push_back(j);
				}
				if((dots[j].first < z && y < dots[j].first) || (dots[j].second < z && y < dots[j].second))
				{
					v.push_back(j);
				}
			}
			//cout << v.size() << " " << u.size() << endl;
			for(int j = 0; j < v.size(); j ++)
			{
				for(int k = 0; k < ndots; k ++)
				{
					if(path[k][v[j]] == 1)
					{
						path[k][ndots] = 1;
					}
				}
			}
			for(int j = 0; j < u.size(); j ++)
			{
				for(int k = 0; k < ndots; k ++)
				{
					if(path[u[j]][k] == 1)
					{
						path[ndots][k] = 1;
					}
				}
			}
			path[ndots][ndots] = 1;
			dots[ndots] = {y, z};
			for(int i = 0; i < ndots; i ++)
			{
				for(int j = 0; j < ndots; j ++)
				{
					if(path[i][ndots] == 1 && path[ndots][j] == 1)
					{
						path[i][j] = 1;
					}
				}
			}
			ndots ++;
			v.clear();
			u.clear();
			for(int i = 0; i < ndots; i ++)
			{
				for(int j = 0; j < ndots; j ++)
				{
					//cout << path[i][j] << " ";
				}
				//cout << endl;
			}
		}
		if(x == 2)
		{
			if(path[y - 1][z - 1] == 1)
			{
				cout << "YES" << endl;
			}
			else
			{
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}