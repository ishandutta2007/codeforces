#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 5e5 + 20;

int d[maxn] , n;

ll x[maxn] , t[maxn] , Add[maxn * 4] , mn[maxn * 4];

void build(int s = 1 , int e = n + 2 , int v = 1)
{
	if(e - s < 2)
	{
		mn[v] = x[s];
		return;
	}
	
	int m = (s + e) / 2;
	build(s , m , 2 * v);
	build(m , e , 2 * v + 1);

	mn[v] = min(mn[2 * v] , mn[2 * v + 1]);
}

void add(int l , int r , int val , int s = 1 , int e = n + 2 , int v = 1)
{
	if(l <= s && e <= r)
	{
		mn[v] += val;
		Add[v] += val;

		return;
	}
	if(r <= s || e <= l)
		return;

	int m = (s + e) / 2;
	add(l , r , val , s , m , 2 * v);
	add(l , r , val , m , e , 2 * v + 1);

	mn[v] = min(mn[2 * v] , mn[2 * v + 1]) + Add[v];
}

ll get(int p , int s = 1 , int e = n + 2 , int v = 1)
{
	if(e - s < 2)
		return mn[v];
	int m = (s + e) / 2;

	if(p < m)
		return get(p , s , m , 2 * v) + Add[v];
	else
		return get(p , m , e , 2 * v + 1) + Add[v];
}

bool is()
{
	return mn[1] >= 0 && (get(n + 1) % 2 == 0);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for(int i = 1; i <= n; i++)
		cin >> d[i];
	d[n + 1] = n;

	sort(d + 1 , d + n + 2);
	reverse(d + 1 , d + n + 2);

	vector<int> ans;
	for(int i = 1; i <= n + 1; i++)
		x[i] = x[i - 1] - d[i];

	for(int i = 1; i <= n + 1; i++)
	{
		int r = min(i , d[i]);
		t[0]++;
		t[r]--;

		Add[r] += d[i];
		Add[i] -= d[i];
	}

	for(int i = 1; i <= n + 1; i++)
	{
		t[i] += t[i - 1];
		x[i] += i * t[i];
		Add[i] += Add[i - 1];
		x[i] += Add[i];
		x[i] += 1LL * i * (i - 1);
	}

	memset(Add , 0 , sizeof Add);
	build();
/*
	for(int i = 1; i <= n + 1; i++)
	{
		for(int j = 1; j < i; j++)
			add(j , j + 1 , min(j , d[i]));
		for(int j = i; j <= n + 1; j++)
			add(j , j + 1 , -d[i]);

		add(i , i + 1 , i * (i - 1));
	}*/

	vector<int> res;
	if(is())
		res.pb(n);

	int pt = 1;
	for(int i = n - 1; i >= 0; i--)
	{
		d[pt]--;
//		for(int j = pt; j <= n + 1; j++)
//			add(j , j + 1 , 1);
		add(pt , n + 2 , 1);

//		for(int j = 1; j < pt; j++)
//			add(j , j + 1 , min(j , d[pt]) - min(j , d[pt] + 1));

		int r = min(pt , d[pt] + 1);
		add(r , pt , -1);
		add(r - 1 , r , min(r - 1 , d[pt]) - min(r - 1 , d[pt] + 1));

		while(pt + 1 <= n + 1 && d[pt + 1] > d[pt])
		{
			add(pt , pt + 1 , d[pt] - d[pt + 1]);
			add(pt , pt + 1 , min(pt , d[pt]) - min(pt , d[pt + 1]));

			swap(d[pt + 1] , d[pt]);
			pt++;
		}

		if(is())
		{
//			for(int j = 1; j <= n + 1; j++)
//				cout << get(j) << " ";
			res.pb(i);
		}
	}
	sort(res.begin() , res.end());
	if(res.empty())
		res.pb(-1);

	for(auto x : res)
		cout << x << " ";
	cout << endl;
}