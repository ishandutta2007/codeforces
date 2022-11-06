#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e3 + 20;
const int dx[2] = {0 , 1};
const int dy[2] = {1 , 0};

string s[maxn];

int mx[maxn][maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , k;
	cin >> n >> k;

	for(int i = 0; i < n; i++)
		cin >> s[i];

	int Mx = 0; 
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			int x = (s[i][j] == 'a');

			mx[i][j] = x;

			if(1 <= i)
				mx[i][j] = max(mx[i][j] , mx[i - 1][j] + x);
			if(1 <= j)
				mx[i][j] = max(mx[i][j] , mx[i][j - 1] + x);

			if(i + j + 1 - mx[i][j] <= k)
				Mx = max(Mx , i + j + 1);
		}

	vector<pair<int , int> > q;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(i + j + 1 - mx[i][j] <= k && i + j + 1 == Mx)
				q.pb({i , j});

	string ans;

	if(!Mx)
		q.pb({0 , 0}) , ans += s[0][0];

	for(int i = 0; i < Mx; i++)
		ans += 'a';

	while((int)ans.size() < 2 * n - 1)
	{
		vector<pair<int , int> > tmp;
		
		sort(q.begin() , q.end());
		q.resize(unique(q.begin() , q.end()) - q.begin());

		char mn = 'z';
		for(auto X : q)
		{
			int x = X.first , y = X.second;
			
			for(int i = 0; i < 2; i++)
				if(x + dx[i] < n && y + dy[i] < n)
					mn = min(mn , s[x + dx[i]][y + dy[i]]);
		}

		for(auto X : q)
		{
			int x = X.first , y = X.second;
			
			for(int i = 0; i < 2; i++)
				if(x + dx[i] < n && y + dy[i] < n && s[x + dx[i]][y + dy[i]] == mn)
					tmp.pb({x + dx[i] , y + dy[i]});
		}

		ans += mn;

		q = tmp;
	}

	cout << ans << endl;
}