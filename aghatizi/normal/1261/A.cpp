#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

int sum[maxn];

void solve()
{
	int n , k;
	cin >> n >> k;
	string s;
	cin >> s;

	vector<int> pos;
	pos.pb(0);
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		cnt += (s[i] == '('? 1 : -1);
		if(!cnt)
			pos.pb(i + 1);
		sum[i + 1] = cnt;
	}
	sum[n + 1] = 0;

	int m = (int)pos.size() - 1;
	vector<pair<int , int> > ans;
	for(int i = 0; i < m; i++)
	{
		if(s[pos[i]] == ')')
		{
			ans.pb({pos[i] , pos[i + 1] - 1});
			reverse(s.begin() + pos[i] , s.begin() + pos[i + 1]);
		}
	}

	if(m < k)
	{
		k -= m;
		int cnt = 0;
		for(int i = 0; i < n && k; i++)
		{
			if(s[i] == '(')
				cnt++;
			else
			{
				if(cnt > 1)
					ans.pb({i - cnt + 1 , i}) , k--;
				cnt--;
			}
		}
	}
	else
	{
		for(int i = 0; i < m - k; i++)
			ans.pb({pos[i + 1] - 1 , pos[i + 1]});
	}

	cout << ans.size() << endl;
	for(auto x : ans)
		cout << x.first + 1 << " " << x.second + 1 << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while(t--)
		solve();
}