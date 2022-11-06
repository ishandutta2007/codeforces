#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)
typedef double ld;
typedef complex<ld> point;

const int maxb = 21;
const int N = (1 << maxb);
const int maxn = (1 << maxb) + 20;
const ld pi = 3.1415926535897932384626433832795028841;

point a[maxn];

void rev(point* a)
{
	for(int i = 0; i < N; i++)
	{
		int k = 0;
		for(int j = 0; j < maxb; j++)
			if(bit(i , j))
				k |= 1 << (maxb - j - 1);

		if(i < k)
			swap(a[k] , a[i]);
	}
}

void mul(point* a , int val)
{
	rev(a);
	for(int eq = 2; eq <= N; eq *= 2)
	{
		point wn = polar((ld)1 , 2 * val * pi / eq);
		for(int i = 0; i < N; i += eq)
		{
			int nxt = eq >> 1;
			point pw = point((ld)1 , (ld)0);
			for(int j = 0; j < nxt; j++)
			{
				point x = a[i + j] + pw * a[i + j + nxt];
				point y = a[i + j] - pw * a[i + j + nxt];
				a[i + j] = x , a[i + j + nxt] = y;
				pw *= wn;
			}
		}
	}
	if(val == -1)
		for(int i = 0; i < N; i++)
			a[i] /= N;
}

bool is[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , m;
	cin >> n >> m;

	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;

		a[x] = point(1 , 0);
		is[x] = 1;
	}

	mul(a , 1);
	for(int i = 0; i < N; i++)
		a[i] *= a[i];
	mul(a , -1);

	for(int i = 0; i <= m; i++)
		if(a[i].real() > 0.5 && !is[i])
			return cout << "NO" << endl , 0;

	vector<int> ans;
	for(int i = 0; i <= m; i++)
		if(a[i].real() < 0.5 && is[i])
			ans.pb(i);

	cout << "YES" << endl << ans.size() << endl;
	for(auto x : ans)
		cout << x << " ";
	cout << endl;
}