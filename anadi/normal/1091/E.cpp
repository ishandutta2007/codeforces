#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
int odd;
int deg[N];
int cnt[N];

LL pref[N];
LL diff[N];

void no(){
	puts("-1");
	exit(0);
}

LL get(int id){
	if(deg[id + 1] <= id)
		return pref[n] - pref[id];
	
	int p = id + 1, k = n;
	while(p < k){
		int m = (p + k + 1) / 2;
		if(deg[m] <= id)
			k = m - 1;
		else
			p = m;
	}
	
	return 1LL * (p - id) * id + pref[n] - pref[p];
}

bool can(int d){
	int p = 0, k = n;
	while(p < k){
		int m = (p + k + 1) / 2;
		if(deg[m] >= d)
			p = m;
		else
			k = m - 1;
	}
	
	int Current = cnt[deg[p]] - cnt[deg[p] - 1];
	for(int i = p; i <= n; ++i){
		if(diff[i] + d - 2 * i - (i < deg[i] ? cnt[deg[i]] - cnt[i] - Current : 0) > 0)
			return false;
		
		if(deg[i + 1] == deg[i])
			++Current;
		else
			Current = 1;
	}

	return true;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &deg[i]);
		odd ^= deg[i] & 1;
		cnt[deg[i]]++;
	}
	
	deg[0] = n;
	for(int i = 1; i <= n; ++i)
		cnt[i] += cnt[i - 1];
	
	sort(deg + 1, deg + n + 1);
	reverse(deg + 1, deg + n + 1);
	
//	for(int i = 1; i <= n; ++i)
//		printf("%d ", deg[i]);
//	puts("");
	
	for(int i = 1; i <= n; ++i)
		pref[i] = pref[i - 1] + deg[i];
	
	LL mn = 0;
	for(int i = 1; i <= n; ++i){
		diff[i] = pref[i] - 1LL * i * (i - 1) - get(i);
		mn = max(mn, diff[i]);
//		printf("%lld ", diff[i]);
	}
	
	if(mn > n || !can(mn))
		no();

	int p = mn, k = n;
	while(p < k){
		int m = (p + k + 1) / 2;
		if(can(m))
			p = m;
		else
			k = m - 1;
	}

	LL mx = p;
	if((mn & 1) != odd)
		++mn;
	if((mx & 1) != odd)
		--mx;
	
	if(mx < mn)
		no();
	
	for(int i = mn; i <= mx; i += 2)
		printf("%d ", i);
	return 0;
}