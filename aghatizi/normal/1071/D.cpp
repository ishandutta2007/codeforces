#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e6 + 20;
const int maxm = 9e2 + 20;

map<vector<int> , int> mp;
map<int , int> mpm;
int cnt;

const int prime[] = {2 , 3 , 5 , 7 , 11, 13 , 17, 19};

int p[maxn] , d[maxm][maxm] , mul[maxm];

vector<int> tmpbt , shit[maxm];

void bt(int mul , int last , int sz = 7)
{
	if(sz == -1)
	{
		shit[cnt] = tmpbt;
		mp[tmpbt] = cnt++;
		return;
	}

	for(int i = 1; ; i++)
	{
		if(i >= last)
		{
			tmpbt.pb(i);
			bt(mul , i , sz - 1);
			tmpbt.pop_back();
		}

		if(mul > 1e8 / prime[sz])
			return;

		mul *= prime[sz];
	}
}

vector<int> handle(int a)
{
	vector<int> ans;
	while(a > 1)
	{
		int k = p[a] , t = 1;

		while(a % k == 0)
			a /= k , t++;
		ans.pb(t);
	}

	while((int)ans.size() < 8)
		ans.pb(1);

	sort(ans.begin() , ans.end());

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	bt(1 , 1);

	for(int i = 2; i < maxn; i++)
		if(!p[i])
			for(int j = i; j < maxn; j += i)
				p[j] = i;

	int m = mp.size() , cntm = 0;

	for(int i = 0; i < m; i++)
	{
		mul[i] = 1;
		for(auto x : shit[i])
			mul[i] *= x;

		if(!mpm.count(mul[i]))
			mpm[mul[i]] = cntm++;
	}

	memset(d , 63 , sizeof d);
	for(int src = 0; src < cntm; src++)
	{
		queue<int> q;
		for(int j = 0; j < m; j++)
			if(mpm[mul[j]] == src)
			{
				q.push(j);
				d[src][j] = 0;
			}

		while(!q.empty())
		{
			int v = q.front();
			q.pop();

			vector<int> tmp;
			for(int i = 0; i < (int)shit[v].size(); i++)
			{
				tmp = shit[v];
				tmp[i]--;

				sort(tmp.begin() , tmp.end());

				if(mp.count(tmp))
				{
					int u = mp[tmp];

					if(d[src][u] > d[src][v] + 1)
					{
						d[src][u] = d[src][v] + 1;
						q.push(u);
					}
				}
			}

			for(int i = (int)shit[v].size() - 1; i >= 0; i--)
			{
				tmp = shit[v];
				tmp[i]++;

				sort(tmp.begin() , tmp.end());

				if(mp.count(tmp))
				{
					int u = mp[tmp];

					if(d[src][u] > d[src][v] + 1)
					{
						d[src][u] = d[src][v] + 1;
						q.push(u);
					}
				}
			}
		}
	}

	int T;
	cin >> T;

	while(T--)
	{
		int a , b;
		cin >> a >> b;

		vector<int> A = handle(a) , B = handle(b);

		if(!mp.count(A) || !mp.count(B))
			cout << 1/0;

		int res = 1e9 , ind1 = mp[A] , ind2 = mp[B];

		for(int i = 0; i < cntm; i++)
			res = min(res , d[i][ind1] + d[i][ind2]);

		cout << res << endl;
	}
}