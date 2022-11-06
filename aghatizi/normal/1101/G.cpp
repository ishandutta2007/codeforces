#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define int ll
#define bit(a , b) (((a)>>(b))&1)

const int maxn = 2e5 + 20;
const int maxb = 40;

int a[maxn] , px[maxn];

bool visited[maxn];

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		px[i + 1] = (px[i] ^ a[i]);
	}
	if(px[n] == 0)
		return cout << -1 << endl , 0;

	int ind = __builtin_ctz(px[n]);
	for(int i = 1; i < n; i++)
		if(bit(px[i] , ind))
			px[i] ^= px[n];
	visited[n] = 1;

	int res = 1;
	for(int j = maxb - 1; j >= 0; j--)
		for(int i = 1; i <= n && j != ind; i++)
			if(!visited[i] && bit(px[i] , j))
			{
				visited[i] = 1;
				for(int k = 1; k <= n; k++)
					if(!visited[k] && bit(px[k] , j))
						px[k] ^= px[i];

				res++;
				break;
			}

	cout << res << endl;
}