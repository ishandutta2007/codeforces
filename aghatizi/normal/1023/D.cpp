#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;

int a[maxn] , b[maxn] , seg[maxn * 4] , frst[maxn] , last[maxn];

void Set(int l , int r , int val , int s , int e , int v)
{
	if(r <= l)
		return;

	if(l <= s && e <= r)
	{
		seg[v] = max(seg[v] , val);
		return;
	}
	if(r <= s || e <= l)
		return;

	int m = (s + e) / 2;

	Set(l , r , val , s , m , 2 * v);
	Set(l , r , val , m , e , 2 * v + 1);
}

int get(int p , int s , int e , int v)
{
	if(e - s < 2)
		return seg[v];

	int m = (s + e) / 2;

	if(p < m)
		return max(get(p , s , m , 2 * v) , seg[v]);
	else
		return max(get(p , m , e , 2 * v + 1) , seg[v]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	memset(frst , 63 , sizeof frst);

	int n , q;
	cin >> n >> q;

	for(int i = 0; i < n; i++)
	{
		cin >> a[i];

		frst[a[i]] = min(frst[a[i]] , i);
		last[a[i]] = max(last[a[i]] , i);
	}

	if(frst[q] > n)
	{
		for(int i = 0; i < n; i++)
			if(a[i] == 0)
			{
				frst[q] = last[q] = i;
				a[i] = q;
				break;
			}

		if(frst[q] > n)
			return cout << "NO" << endl , 0;
	}

	for(int i = 1; i <= q; i++)
		Set(frst[i] , last[i] + 1 , i , 0 , n , 1);

	for(int i = 0; i < n; i++)
	{
		b[i] = get(i , 0 , n , 1);

		if(a[i] != b[i] && a[i])
			return cout << "NO" << endl , 0;
	}

	cout << "YES" << endl;

	int x = n;

	for(int i = 0; i < n; i++)
		if(a[i] != 0)
		{
			x = i;
			break;
		}

	for(int i = x; i < n; i++)
		if(!a[i])
			b[i] = b[i - 1];

	if(x == n)
		b[n - 1] = q , x--;

	for(int i = x - 1; i >= 0; i--)
		b[i] = b[i + 1];

	for(int i = 0; i < n; i++)
		cout << b[i] << " ";
	cout << endl;

}