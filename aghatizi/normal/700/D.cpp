#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;
const int sq = 320;

int a[maxn];

int l[maxn] , r[maxn] , ind[maxn];
ll ans[maxn];

int cnt[maxn] , tcnt[maxn];

vector<int> gb;

vector<pair<int , int> > vec;

bool cmp(int a , int b)
{
	if(l[a] / sq != l[b] / sq)
		return l[a] < l[b];
	else
		return r[a] < r[b];
}

void add(int x)
{
	tcnt[cnt[x]]--;
	cnt[x]++;
	tcnt[cnt[x]]++;
	if(tcnt[cnt[x]] == 1)
		gb.pb(cnt[x]);
}

void rem(int x)
{
	tcnt[cnt[x]]--;
	cnt[x]--;
	if(cnt[x])
	{
		tcnt[cnt[x]]++;
		if(tcnt[cnt[x]] == 1)
			gb.pb(cnt[x]);
	}
}

void modify()
{
	vec.clear();
	for(auto x : gb)
		if(tcnt[x])
			vec.pb({x , tcnt[x]});

	sort(vec.begin() , vec.end());
	vec.resize(unique(vec.begin() , vec.end()) - vec.begin());
	gb.clear();

	for(auto x : vec)
		gb.pb(x.first);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	gb.reserve(1 << 20);
	vec.reserve(1 << 20);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	int q;
	cin >> q;

	for(int i = 0; i < q; i++)
		cin >> l[i] >> r[i] , l[i]-- , ind[i] = i;

	sort(ind , ind + q , cmp);

	int L = 0 , R = 0;
	for(int i = 0; i < q; i++)
	{
		int x = ind[i];
		if(L / sq != l[x] / sq)
		{
			memset(cnt , 0 , sizeof cnt);
			memset(tcnt , 0 , sizeof tcnt);
			gb.clear();
			R = L;
		}
		while(R < r[x])
			add(a[R]) , R++;
		while(l[x] < L)
			L-- , add(a[L]);
		while(r[x] < R)
			R-- , rem(a[R]);
		while(L < l[x])
			rem(a[L]) , L++;

		modify();
		vector<pair<int , int> > tmp;
		int last = -1 , pt1 = 0 , pt2 = 0;
		ll res = 0;

		while(pt1 < (int)vec.size() || pt2 < (int)tmp.size())
		{
			pair<int , int> mn = {-1 , -1};
			if(pt1 == (int)vec.size())
				mn = tmp[pt2++];
			else if(pt2 == (int)tmp.size())
				mn = vec[pt1++];
			else
			{
				if(vec[pt1].first < tmp[pt2].first)
					mn = vec[pt1++];
				else
					mn = tmp[pt2++];
			}

			if(last != -1)
			{
				mn.second--;
				res += mn.first + last;
				tmp.pb(make_pair(mn.first + last , 1));
			}

			if(mn.second > 1)
			{
				res += 1LL * (mn.second / 2) * (mn.first * 2);
				tmp.pb(make_pair(mn.first * 2 , mn.second / 2));
			}
			mn.second %= 2;
			if(mn.second)
				last = mn.first;
			else
				last = -1;
		}

		ans[x] = res;
	}

	for(int i = 0; i < q; i++)
		cout << ans[i] << endl;
	cout << endl;
}