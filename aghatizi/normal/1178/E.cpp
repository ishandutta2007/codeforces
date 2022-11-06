#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e6 + 20;

string s;

void solve(char ch)
{
	vector<pair<int , int> > tmp;
	int n = s.size() , last = 0;
	char a = 'a' , b = 'b';

	if(ch == a)
		a = 'c';
	if(ch == b)
		b = 'c';
	for(int i = 0; i < n; i++)
		if(s[i] == ch)
		{
			tmp.pb({i - last , (s[last] == a)});
			last = i + 1;
		}

	tmp.pb({n - last , s[last] == a});
	int m = tmp.size();

	string res;
	for(int i = 0; m - i - 1 >= i; i++)
	{
		int j = m - i - 1;
		if(i == j)
		{
			if(tmp[i].first % 2 == 0)
				tmp[i].first--;
			for(int j = 0; j <= tmp[i].first / 2; j++)
			{
				if((j + tmp[i].second) % 2)
					res += a;
				else
					res += b;
			}
		}
		else
		{
			int mn = min(tmp[i].first , tmp[j].first);
			bool f = 0;
			for(int k = mn; !f && k; k--)
			{
				for(int x = 0; x < 2; x++)
				{
					if(tmp[i].second != x && k > tmp[i].first - 1)
						continue;

					int shit = (tmp[j].first - 1 + tmp[j].second) % 2;
					if(shit != x && k > tmp[j].first - 1)
						continue;

					for(int t = 0; t < k; t++)
					{
						if((x + t) % 2)
							res += a;
						else
							res += b;
					}
					f = 1;
					break;
				}
			}

			res += ch;
		}
	}

	string tmpx = res;
	tmpx.pop_back();
	reverse(tmpx.begin() , tmpx.end());
	res += tmpx;

	if((int)res.size() >= n / 2)
		cout << res << endl , exit(0);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> s;
	solve('a');
	solve('b');
	solve('c');

	while(1);
}