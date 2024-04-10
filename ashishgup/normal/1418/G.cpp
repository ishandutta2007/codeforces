#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 5e5 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

int add(int val1, int val2)
{
	int val = 0;
	vector<int> cur;
	while(val1 || val2)
	{
		int cv1 = val1 % 3;
		int cv2 = val2 % 3;
		cur.push_back((cv1 + cv2) % 3);
		val1 /= 3;
		val2 /= 3;
	}
	reverse(cur.begin(), cur.end());
	for(auto &it:cur)
		val = val * 3 + it;
	return val;
}

int n;
int a[N], store[N], pref[N];
vector<int> v;
map<int, int> m;
queue<int> q[N];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		store[i] = getRand(0, 2e18);
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	m[0]++;
	int ans = 0, cur = 0, idx = 1;
	for(int i = 1; i <= n; i++)
	{
		while(q[a[i]].size() >= 3)
		{
			int x = q[a[i]].front();
			q[a[i]].pop();
			while(idx <= x)
			{
				m[pref[idx - 1]]--;
				idx++;
			}
		}
		cur = add(cur, store[a[i]]);
		ans += m[cur];
		m[cur]++;
		pref[i] = cur;
		q[a[i]].push(i);
	}
	cout << ans;
	return 0;
}