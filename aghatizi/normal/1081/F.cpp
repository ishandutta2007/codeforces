#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define p(a) ((a)&1)

const int maxn = 1e5 + 20;

bool s[maxn] , res[maxn] , tmp[maxn];

int n;

int get(int l , int r)
{
	cout << "? " << l + 1 << " " << r + 1 << endl;
	int x = 0;
/*
	if(rand() % 2)
		for(int i = 0; i <= r; i++)
			tmp[i] ^= 1;
	else
		for(int i = l; i < n; i++)
			tmp[i] ^= 1;

	for(int i = 0; i < n; i++)
		x += tmp[i];*/
	cin >> x;

	if(x == -1)
		cout << 1/0;
	return x;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

//	tmp[0] = 1 , tmp[1] = 1 , tmp[2] = 1;

	int t;
	cin >> n >> t;

	if(n == 1)
		return cout << "! " << t << endl , 0;

	if(n&1)
	{
		while(1)
		{
			int nt = get(1 , n - 1);

			if(p(nt) == p(t))
			{
				for(int j = 1; j < n; j++)
					s[j] ^= 1;

				res[0] = s[0];
				if(t - (t + n - 1 - nt) / 2)
					res[0] ^= 1 , s[0] = 1;
				else
					s[0] = 0;
				
				t = nt;
				break;
			}

			t = nt;
			for(int i = 0; i < n; i++)
				s[i] ^= 1;
		}

		for(int i = 1; i < n; i++)
			while(1)
			{
				int ps = 0;
				for(int j = 0; j < i; j++)
					ps += s[j];

				int nt = get(i - 1 , i);
				if(p(nt) == p(t ^ (i + 1)))
				{
					for(int j = 0; j <= i; j++)
						s[j] ^= 1;

					if(t - ps + i + 1 - ps == nt)
						res[i] = s[i] ^ 1 , s[i] = 1;
					else
						res[i] = s[i] , s[i] = 0;

					t = nt;
					break;
				}

				t = nt;
				for(int j = i - 1; j < n; j++)
					s[j] ^= 1;
			}
	}
	else
	{
		for(int i = 0; i < n; i++)
			while(1)
			{
				int ps = 0;
				for(int j = 0; j < i; j++)
					ps += s[j];

				int nt = get(i , i);
				if(p(nt) == p(t ^ (i + 1)))
				{
					for(int j = 0; j <= i; j++)
						s[j] ^= 1;

					if(t - ps + i + 1 - ps == nt)
						res[i] = s[i] ^ 1 , s[i] = 1;
					else
						res[i] = s[i] , s[i] = 0;

					t = nt;
					break;
				}

				t = nt;
				for(int j = i; j < n; j++)
					s[j] ^= 1;
			}
	}

	cout << "! ";
	for(int i = 0; i < n; i++)
		cout << res[i];
	cout << endl;
}