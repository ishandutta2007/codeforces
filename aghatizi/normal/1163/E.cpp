#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)

const int maxn = (1 << 18) + 20;

int a[maxn] , wtf;

bool is[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	vector<int> res;
	for(int b = 0; b <= 18; b++)
	{
		vector<int> tmp;
		for(int i = 0; i < n; i++)
			if(a[i] < (1 << b))
				tmp.pb(a[i]);

		auto shit = tmp;
		memset(is , 0 , sizeof is);
		int m = tmp.size();

		vector<int> vals;
		for(int j = 0; j < b; j++)
		{
			int found = -1;
			for(int i = 0; i < m; i++)
				if(!is[i] && bit(tmp[i] , j))
					found = i;

			if(found == -1)
				break;
			vals.pb(shit[found]);
			is[found] = 1;

			for(int i = 0; i < m; i++)
				if(!is[i] && bit(tmp[i] , j))
					tmp[i] ^= tmp[found];
		}

		if((int)vals.size() != b)
			continue;

		int nw = 0;
		memset(is , 0 , sizeof is);
		is[0] = 1;

		vector<int> ans = {0};
		for(int i = 1; i < (1 << b); i++)
		{
			bool f = 0;
			for(auto x : vals)
				if(!is[nw ^ x])
				{
					nw ^= x;
					is[nw] = 1;
					ans.pb(nw);
					f = 1;
					break;
				}

			if(!f)
				break;
		}

		if((int)ans.size() != (1 << b))
			continue;

		res = ans;
		wtf = b;
	}

	cout << wtf << endl;
	for(auto x : res)
		cout << x << " ";
	cout << endl;
}