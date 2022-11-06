#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ld long double

const int maxn = 1e6 + 20;

int a[maxn] , b[maxn] , shit[maxn];

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		int n;
		scanf("%d", &n);

		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]) , b[i] = a[i];

		sort(b , b + n);

		int m = unique(b , b + n) - b;

		for(int i = 0; i < n; i++)
			shit[lower_bound(b , b + m , a[i]) - b]++;

		bool f = 1;

		vector<int> tmp;
		for(int i = 0; i < m; i++)
		{
			if(shit[i] >= 4)
			{
				printf("%d %d %d %d\n" , b[i] , b[i] , b[i] , b[i]);
				f = 0;
				break;
			}
			if(shit[i] >= 2)
				tmp.pb(i);
		}

		pair<ld , int> an = {1e9 , -1};

		if(f)
		{
			for(int i = 0; i + 1 < (int)tmp.size(); i++)
			{
				int ind1 = tmp[i] , ind2 = tmp[i + 1];

				pair<ld , int> shiit = {(ld)b[ind1] / (ld)b[ind2] + (ld)b[ind2] / (ld)b[ind1] , i};

				an = min(shiit , an);
			}

			int ind1 = tmp[an.second] , ind2 = tmp[an.second + 1];

			printf("%d %d %d %d\n", b[ind1] , b[ind1] , b[ind2] , b[ind2]);
		}

		for(int i = 0; i < m; i++)
			shit[i] = 0;
	}
}