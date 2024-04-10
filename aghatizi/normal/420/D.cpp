#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e6 + 20;

int t[maxn * 4] , n , q , a[maxn] , val[maxn] , is[maxn];

void Turn(int p , int val , int s = 0 , int e = n + q , int v = 1)
{
	if(e - s < 2)
	{
		t[v] += val;
		return;
	}

	int m = (s + e) / 2;

	if(p < m)
		Turn(p , val , s , m , 2 * v);
	else
		Turn(p , val , m , e , 2 * v + 1);

	t[v] = t[2 * v] + t[2 * v + 1];
}

int get(int val , int s = 0 , int e = n + q , int v = 1)
{
	if(e - s < 2)
		return s;

	int m = (s + e) / 2;

	if(val >= t[2 * v])
		return get(val - t[2 * v] , m , e , 2 * v + 1);
	else
		return get(val , s , m , 2 * v);
}

int main()
{
	scanf("%d%d", &n, &q);

	memset(val , -1 , sizeof val);

	for(int i = q; i < n + q; i++)
		Turn(i , 1) , a[i] = i - q;

	for(int i = q - 1; i >= 0; i--)
	{
		int x , y;
		scanf("%d%d", &x, &y);
		y--;

		int k = get(y);
		Turn(k , -1);
		int p = a[k];

		if(val[p] != -1 && val[p] != x)
			return printf("-1\n") , 0;

		Turn(i , 1);
		val[p] = x;
		a[i] = p;
	}

	for(int i = 0; i < n; i++)
		if(val[i] != -1)
			is[val[i]]++;

	vector<int> tmp;
	for(int i = 1; i <= n; i++)
	{
		if(is[i] > 1)
			return printf("-1\n") , 0;

		if(!is[i])
			tmp.pb(i);
	}

	reverse(tmp.begin() , tmp.end());

	for(int i = 0; i < n; i++)
		if(val[i] == -1)
			val[i] = tmp.back() , tmp.pop_back();

	for(int i = 0; i < n; i++)
		printf("%d ", val[i]);
	printf("\n");
}