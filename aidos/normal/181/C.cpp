#include<iostream>
#include<string>
#include<vector>
#include <cmath>
#include<algorithm>
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define LL long long
using namespace std;
typedef pair<int, int> pii;
const double eps = 1e-9;
int a[11][111],b[11][111],c[11][111];
int main()
{
	int n,m,k;
	int res = 0;
	cin>>n>>m>>k;
	string s;
	for(int i = 0; i < n; i++)
	{
		cin>>s;
		for(int j = 0; j < m; j++)
			cin>>a[i][j]>>b[i][j]>>c[i][j];
	}
	vector<pii> v(m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			if (i == j) continue;
			for(int r = 0; r < m; r++)
			{
				v[r].first = b[j][r] - a[i][r];
				v[r].second = c[i][r];
			}
			sort(all(v));
			int K = k,sum = 0;
			for(int r = m - 1; r >= 0; r--)
			{
				if (v[r].first > 0)
				{
					if (v[r].second >= K)
					{
						sum += K * v[r].first;
						break;
					}
					K -= v[r].second;
					sum += v[r].second * v[r].first;
				} else break;
			}
			res = max(res,sum);
		}
	cout<<res<<endl;	
 	return 0;
}