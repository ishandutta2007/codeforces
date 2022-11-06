#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)

const int maxn = (1 << 20) + 20;
const int maxk = 23;

int mn[maxn] , mx[maxn] , p[maxk];

string s[maxn] , t[maxn];

int get(string s)
{
	int res = 0;
	for(int i = 0; i < (int)s.size(); i++)
		res = res * 2 + (s[i] - '0');

	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , m , k;
	cin >> n >> m >> k;

	for(int i = 0; i < k; i++)
		p[i] = i;

	cin >> s[0] >> t[0];

	memset(mn , 63 , sizeof mn);
	memset(mx , -1 , sizeof mx);

	mn[get(s[0])] = min(mn[get(s[0])] , 0);
	mx[get(t[0])] = max(mx[get(t[0])] , 0);

	for(int i = 1; i <= n; i++)
	{
		int a , b;
		cin >> a >> b;
		a-- , b--;

		swap(p[a] , p[b]);

		s[i] = s[0] , t[i] = t[0];
		for(int j = 0; j < k; j++)
		{
			s[i][p[j]] = s[0][j];
			t[i][p[j]] = t[0][j];
		}

		mn[get(s[i])] = min(mn[get(s[i])] , i);
		mx[get(t[i])] = max(mx[get(t[i])] , i);
	}

	int s1 = __builtin_popcount(get(s[0]));
	int t1 = __builtin_popcount(get(t[0]));

	pair<int , int> res = {-1 , 0};
	for(int mask = (1 << k) - 1; mask >= 0; mask--)
	{
		for(int i =	0; i < k; i++)
			if(bit(mask , i))
			{
				mn[mask ^ (1 << i)] = min(mn[mask ^ (1 << i)] , mn[mask]);
				mx[mask ^ (1 << i)] = max(mx[mask ^ (1 << i)] , mx[mask]);
			}

		if(mx[mask] - mn[mask] >= m)
			res = max(res , make_pair(2 * __builtin_popcount(mask) + k - s1 - t1 , mask));
	}

	cout << res.first << endl;
	cout << mn[res.second] + 1 << " " << mx[res.second] << endl;
}