#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

const int MAXN = 1e7 + 5;

int N;
int p[MAXN];
int phi[MAXN];
vector <int> nums, primes;
int cnt[MAXN];
int suff[MAXN];

void load() {
	scanf("%d", &N);
}

void init() {
	for (int i = 2; i <= N; i++)
		if (!p[i])
			for (int j = i; j <= N; j += i)
				if (!p[j])
					p[j] = i;
	for (int i = 1; i <= N; i++)
		phi[i] = i;
	for (int i = 1; i <= N; i++)
		for (int j = 2 * i; j <= N; j += i)
			phi[j] -= phi[i];
}

ll solve() {
	ll x = (ll)N * (N - 1) / 2;
	for (int i = 2; i <= N; i++)
		x -= phi[i];
	
	for (int i = 2; i <= N; i++)
		if (p[i] < i || i <= N / 2)
			nums.push_back(i);
	
	for (auto it : nums)
		cnt[p[it]]++;
	
	for (int i = N; i; i--)
		cnt[i] += cnt[i + 1];
	
	ll z = 0;
	for (auto it : nums)
		if (p[it] == it) 
			z += cnt[N / it + 1] - (it > N / it ? cnt[it] - cnt[it + 1] : 0);
		
	for (auto it : nums)
		if (p[it] == it)
			suff[it]++;
	
	for (int i = N; i; i--)
		suff[i] += suff[i + 1];
	
	ll sum = 0;
	for (auto it : nums)
		if (p[it] == it)
			sum += suff[N / it + 1] - (it > N / it);
	z -= sum / 2;
	
	return (ll)nums.size() * ((int)nums.size() - 1) + z - x;
}

int main() {
	load();
	init();
	printf("%lld\n", solve());
	return 0;
}