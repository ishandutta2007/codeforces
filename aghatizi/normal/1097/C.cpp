#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

int a[maxn];

map<int , int> mp , pm;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> x , y;
	int t = 0;
	for(int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		int mn = 0;
		for(auto ch : s)
		{
			if(ch == '(')
				a[i]++;
			else
				a[i]--;

			mn = min(mn , a[i]);
		}

		if(mn < 0 && mn != a[i])
			continue;

		if(mn == 0 && a[i] == 0)
		{
			t++;
			continue;
		}

		if(a[i] > 0)
			mp[a[i]]++;
		else if(mn == a[i])
			pm[a[i]]++;
	}

	t /= 2;

	for(auto x : mp)
		t += min(x.second , pm[-x.first]);

	cout << t << endl;
}