#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define X first
#define Y second

const int maxn = 1e6 + 20;

template <class T1 , class T2>
struct cht
{
	public:

		set < pair <T1 , T2> > line;
		set < pair < ll , pair <T1 , T2> > > sorted_by_time;
		set < pair < pair <T1 , T2> , ll > > sorted_by_slope;

		void swap(cht& x)
		{
			line.swap(x.line);
			sorted_by_time.swap(x.sorted_by_time);
			sorted_by_slope.swap(x.sorted_by_slope);
		}

		void clear()
		{
			line.clear();
			sorted_by_slope.clear();
			sorted_by_time.clear();
		}

		void add(T1 x1 , T2 x2)
		{
			pair <T1 , T2> x=mp(x1 , x2);
			pair < pair <T1 , T2> , ll > ans=mp(x , -INF);

			line.insert(x);

			while (sorted_by_slope.size()>0)
			{
				typename set < pair < pair <T1 , T2> , ll > > :: iterator z=sorted_by_slope.upper_bound(mp(x , -INF));

				if (z==sorted_by_slope.begin())
				{
					ans=mp(x , -INF);
					break;
				}

				z--;
				pair <T1 , T2> y=(z->X);
				ll t=intersection(y , x);

				if (t<=(z->Y))
				{
					sorted_by_time.erase(mp((z->Y) , y));
					sorted_by_slope.erase(z);
				}
				else
				{
					ans=mp(x , t);
					break;
				}
			}

			while (sorted_by_slope.size()>0)
			{
				typename set < pair < pair <T1 , T2> , ll > > :: iterator z=sorted_by_slope.lower_bound(mp(x , -INF));

				if (z==sorted_by_slope.end())
				{
					break;
				}

				pair <T1 , T2> y=(z->X);
				ll old_t=(z->Y) , new_t=intersection(x , y);

				if (new_t<=ans.Y)
				{
					if (z==sorted_by_slope.begin())
					{
						sorted_by_slope.erase(mp(y , old_t));
						sorted_by_time.erase(mp(old_t , y));

						sorted_by_slope.insert(mp(y , -INF));
						sorted_by_time.insert(mp(-INF , y));
					}
					else
					{
						z--;
						ll t=intersection(z->X , y);

						sorted_by_slope.erase(mp(y , old_t));
						sorted_by_time.erase(mp(old_t , y));

						sorted_by_slope.insert(mp(y , t));
						sorted_by_time.insert(mp(t , y));
					}

					return;
				}
				else
				{
					z++;

					if (z!=sorted_by_slope.end())
					{
						if ((z->Y)<=new_t)
						{
							sorted_by_slope.erase(mp(y , old_t));
							sorted_by_time.erase(mp(old_t , y));
						}
						else
						{
							sorted_by_slope.erase(mp(y , old_t));
							sorted_by_time.erase(mp(old_t , y));

							sorted_by_slope.insert(mp(y , new_t));
							sorted_by_time.insert(mp(new_t , y));

							break;
						}
					}
					else
					{
						sorted_by_slope.erase(mp(y , old_t));
						sorted_by_time.erase(mp(old_t , y));

						sorted_by_slope.insert(mp(y , new_t));
						sorted_by_time.insert(mp(new_t , y));

						break;
					}
				}
			}

			sorted_by_slope.insert(ans);
			sorted_by_time.insert(mp(ans.Y , ans.X));
		}

		ll max_value(ll t)
		{
			typename set < pair < ll , pair <T1 , T2> > > :: iterator z=sorted_by_time.upper_bound(mp(t , mp(std::numeric_limits <T1> :: max() , std::numeric_limits <T2> :: max())));
			z--;

			return t*(ll)((z->Y).X)+(ll)((z->Y).Y);
		}

	private:

		ll INF=1e18+10;

		ll intersection(pair <T1 , T2> x , pair <T1 , T2> y)
		{
			if (y.X==x.X)
			{
				if (y.Y>=x.Y)
				{
					return -INF;
				}

				return INF;
			}

			return ((x.Y-y.Y)/(y.X-x.X))+((x.Y-y.Y)%(y.X-x.X)>0);
		}
};

cht<ll , ll> C;

int ind[maxn] , x[maxn] , y[maxn];

ll a[maxn] , dp[maxn];

bool cmp(int a , int b)
{
	return make_pair(x[a] , y[a]) < make_pair(x[b] , y[b]);
}

int main()
{
	int n;
	scanf("%d", &n);

	for(int i = 1; i <= n; i++)
	{
		scanf("%d%d%I64d", &x[i], &y[i], &a[i]);
		ind[i] = i;
	}

	sort(ind + 1 , ind + n + 1 , cmp);

	C.add(0 , 0);

	for(int j = 1; j <= n; j++)
	{
		int i = ind[j];
		dp[i] = C.max_value(y[i]) + 1LL * x[i] * y[i] - a[i];
		C.add(-x[i] , dp[i]);
	}

	cout << *max_element(dp , dp + n + 1) << endl;
}