#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define div DDD

const int maxn = 1e5 + 20;
const int maxk = 7000 + 20;

bitset<maxk> a[maxn] , div[maxk] , tmp[maxk];

vector<int> val;

int main()
{
	for(int i = 1; i < maxk; i++)
		for(int j = i; j < maxk; j += i)
			div[j][i] = 1;

	for(int i = 1; i < maxk; i++)
	{
		bool is = 1;
		for(int j = 2; j <= i && is; j++)
			if(div[i][j] && (i / j) % j == 0)
				is = 0;

		if(is)
			val.pb(i);
	}

	for(int i = 1; i < maxk; i++)
		for(auto x : val)
			if(i * x < maxk)
				tmp[i][i * x] = 1;

	int n , q;
	scanf("%d%d", &n, &q);

	while(q--)
	{
		int type;
		scanf("%d", &type);

		if(type == 1)
		{
			int ind , v;
			scanf("%d%d", &ind, &v);
			ind--;

			a[ind] = div[v];
		}
		if(type == 2)
		{
			int x , y , z;
			scanf("%d%d%d", &x, &y, &z);
			x-- , y-- , z--;

			a[x] = a[y]^a[z];
		}
		if(type == 3)
		{
			int x , y , z;
			scanf("%d%d%d", &x, &y, &z);
			x-- , y-- , z--;

			a[x] = a[y]&a[z];
		}
		if(type == 4)
		{
			int ind , v;
			scanf("%d%d", &ind, &v);
			ind--;
			
			printf("%d", (int)(a[ind]&tmp[v]).count() % 2);
		}
	}
	
	printf("\n");
}