#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int maxN = 100500;
bool isNotPrime[maxN];
vector<int> primes;
vector<char> isBad;

void calc()
{
	for (int i = 2; i < maxN; i++)
		if (!isNotPrime[i])
		{
			primes.push_back(i);
			if (i * (long long)i < maxN)
				for (int j = i * i; j < maxN; j += i)
					isNotPrime[j] = true;
		}
}

set<int> b;

int f(int x)
{
	int xo = x;
	int ans = 0;
	
	for (int j = 0; j < (int)primes.size(); j++)
		while (x % primes[j] == 0)
		{
			x /= primes[j];
			if (isBad[j])
				ans--;
			else
				ans++;
		}
		
	if (x != 1)
		ans += b.count(x) ? -1 : 1;
	
	//printf("f(%d) is %d\n", xo, ans);
	return ans;
}

int main()
{
	#ifdef LOCAL
	freopen("b.in", "r", stdin);
	#endif
	
	calc();
	
	int n, nBad;
	scanf("%d %d", &n, &nBad);
	
	vector<int> a(n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	
	for (int i = 0; i < nBad; i++) { int x; scanf("%d", &x); b.insert(x); }
	
	isBad.resize(primes.size());
	for (int i = 0; i < (int)primes.size(); i++)
	{
		isBad[i] = b.count(primes[i]);
		//if (i < 10)
		//	printf("prime %d, bad %d\n", primes[i], isBad[i]);
	}
	
	vector<int> pgcd(n);
	pgcd[0] = a[0];
	for (int i = 1; i < n; i++)
		pgcd[i] = __gcd(pgcd[i - 1], a[i]);
	
	int divBy = 1;
	for (int i = n - 1; i >= 0; i--)
	{
		int can = pgcd[i] / divBy;
		
		if (f(can) < 0)
			divBy *= can;
			
		a[i] /= divBy;
	}
	
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += f(a[i]);
	printf("%d\n", ans);
	
	return 0;
}