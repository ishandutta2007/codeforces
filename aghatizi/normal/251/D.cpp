#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)

const int maxn = 1e5 + 20;
const int maxb = 62;

ll a[maxn] , val[maxb] , t[maxb] , x[10];
bitset<maxn> num[maxb] , res;

vector<int> inds;
void add(ll x , int ind)
{
	int pnt = -1;
	ll tmp = x;
	for(int j = 0; j < maxb; j++)
	{
		int i = inds[j];
		if(bit(tmp , i))
		{
			if(val[i] == -1)
			{
				pnt = j;
				break;
			}
			else
				tmp ^= val[i];
		}
	}

	if(pnt == -1)
		return;

	int k = inds[pnt];
	num[k][ind] = 1;

	tmp = x;
	for(int j = 0; j < maxb; j++)
	{
		int i = inds[j];
		if(bit(tmp , i) && val[i] != -1)
			tmp ^= val[i] , num[k] ^= num[i];
	}

	for(int j = 0; j < pnt; j++)
	{
		int i = inds[j];
		if(val[i] != -1 && bit(val[i] , k))
			num[i] ^= num[k] , val[i] ^= tmp;
	}
/*
	for(int j = pnt + 1; j < maxb; j++)
	{
		int i = inds[j];
		if(bit(tmp , i) && val[i] != -1)
		{
			tmp ^= val[i];
			num[k] ^= num[i];
		}
	}
*/
	val[k] = tmp;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(val , -1 , sizeof val);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	for(int i = 0; i < n; i++)
		for(int j = 0; j < maxb; j++)
			t[j] ^= bit(a[i] , j);

	for(int i = maxb - 1; i >= 0; i--)
		if(!t[i])
			inds.pb(i);
	for(int i = maxb - 1; i >= 0; i--)
		if(t[i])
			inds.pb(i);

	for(int i = 0; i < n; i++)
		add(a[i] , i);

	for(int i = 0; i < maxb; i++)
		res ^= num[i];

	for(int i = 0; i < n; i++)
		x[res[i]] ^= a[i];

//	cout << x[0] + x[1] << endl;
//	cout << x[0] << " " << x[1] << endl;
	for(int i = 0; i < n; i++)
		cout << (int)res[i] + 1 << " ";
	cout << endl;
}