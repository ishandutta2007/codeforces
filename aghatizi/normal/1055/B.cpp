#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define int ll

const int maxn = 1e5 + 20;

int a[maxn] , cmp;

int is[maxn] , l;

void handle(int x)
{
	cmp -= is[x];

	if(a[x] >= l && (!x || a[x - 1] < l))
		is[x] = 1;
	else
		is[x] = 0;

	cmp += is[x];
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , q;
	cin >> n >> q >> l;
	l++;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	for(int i = 0; i < n; i++)
		if(a[i] >= l && (!i || a[i - 1] < l))
			is[i] = 1 , cmp++;

	while(q--)
	{
		int type;
		cin >> type;

		if(type == 0)
			cout << cmp << endl;
		else
		{
			int p , d;
			cin >> p >> d;
			p--;

			a[p] += d;
			handle(p);
			handle(p + 1);
		}
	}

}