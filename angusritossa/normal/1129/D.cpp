#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
#define MOD 998244353
#define R 220
typedef long long ll;
int nex[300010];
int hmis[300010];
ll val[300010];
queue<int> available;
struct hashmap
{
	int hash(int a)
	{
		a ^= 235796;
		a += 38932;
		a %= 2*R+3;
		return a;
	}
	int buckets[2*R+3];
	ll at(int a)
	{
		int b = hash(a);
		int i = buckets[b];
		while (i)
		{
			if (hmis[i] == a) return val[i];
			i = nex[i];
		}
		return 0;
	}
	void change(int a, ll add)
	{
		int b = hash(a);
		int i = buckets[b];
		int pre = 0;
		while (i)
		{
			if (hmis[i] == a) 
			{
				val[i] += add;
				if (!val[i])
				{
					if (pre)
					{
						nex[pre] = nex[i];
					}
					else
					{
						buckets[b] = nex[i];
					}
					available.push(i);
				}
				return;
			}
			pre = i;
			i = nex[i];
		}
		i = available.front();
		available.pop();
		nex[i] = buckets[b];
		hmis[i] = a;
		buckets[b] = i;
		val[i] = add;
	}
};

hashmap amwith[100010/R+2];
ll bucketoffset[100010/R+2], bucketans[100010/R+2], dp[100010], is[100010];
int n, k, a[100010]; // assuming coordinate compressed data
int lastof[100010], secondlastof[100010];
ll update(int s, int e, ll add)
{
	D("update %d to %d with %lld\n", s, e, add);
	ll ans = 0;
	for (int i = 0, b = 0; i <= n; i += R, b++)
	{
		int j = min(n, i+R-1);
		if (s <= i && j <= e)
		{
			// Entirely contains this range
			if (add == -1)
			{
				bucketoffset[b]--;
				bucketans[b] += amwith[b].at(k-bucketoffset[b]);
			}
			else
			{
				bucketans[b] -= amwith[b].at(k-bucketoffset[b]);
				bucketoffset[b]++;
			}
		}
		else if ((s <= i && e >= i) || (s <= j && e >= j) || (i <= s && e <= j))
		{
			// Partial within
			for (int a = i; a <= j; a++)
			{
				if (s <= a && a <= e)
				{
					amwith[b].change(is[a], -dp[a]);
					if (add == -1)
					{
						is[a]--;
						if (is[a] == k-bucketoffset[b])
						{
							// we can now contain it
							bucketans[b] += dp[a];
						}
					}
					else
					{
						if (is[a] == k-bucketoffset[b])
						{
							// we can no longer contain it
							bucketans[b] -= dp[a];
						}
						is[a]++;
					}
					amwith[b].change(is[a], dp[a]);
				}
			}
		}
		ans += bucketans[b];
		D("b %d: %lld\n", i, bucketans[i]);
	}
	return ans;
}
void add(int a)
{
	int b = a/R;
	// is[a] == 0
	amwith[b].change(bucketoffset[b], dp[a]);
	if (0 <= k-bucketoffset[b])
	{
		bucketans[b] += dp[a];
	}
	D("adding %d (%lld) to %d, offset %lld, bucketval %lld\n", a, dp[a], b, bucketoffset[b], bucketans[b]);
//	D("%lld\n", amwith[b][bucketoffset[b]]);
}
int main()
{
	for (int i = 1; i < 300010; i++) available.push(i);
	scanf("%d%d", &n, &k);
	dp[0] = 1;
	add(0);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
	{
		int l = lastof[a[i]];
		int ll = secondlastof[a[i]];
		secondlastof[a[i]] = l;
		lastof[a[i]] = i;
		// update l to i-1 with +1
		dp[i] = update(l, i-1, 1);
		// update ll to l-1 with -1
		if (ll < l)
		{
			dp[i] = update(ll, l-1, -1);
		}
		dp[i] %= MOD;
		D("%d: %lld\n\n", i, dp[i]);
		add(i);
	}
	printf("%lld\n", dp[n]);
}