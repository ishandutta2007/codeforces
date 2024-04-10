#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;

int n, k, m;
LL res = 0LL;

int tab[N];
int pref[N], suf[N];

LL solve(vector <int> cur){
	int wsk = 1;
	LL ret = 0LL;

	for(int v: cur){
		tab[wsk] = v;
		pref[wsk] = 1;
		if(tab[wsk] == tab[wsk - 1])
			pref[wsk] += pref[wsk - 1];
		
		if(pref[wsk] == k){
			ret += k;
			wsk -= k;
		}
		
		++wsk;
	}
	
	return ret;
}

int main(){
	scanf("%d %d %d", &n, &k, &m);
	LL start = 1LL * n * m;
	for(int i = 1; i <= n; ++i){
		scanf("%d", &tab[i]);
		if(tab[i] == tab[i - 1])
			pref[i] = pref[i - 1] + 1;
		else
			pref[i] = 1;

		if(pref[i] == k){
			n -= k;
			i -= k;
			res += 1LL * k * m;
		}
	}
	
	if(m <= 2){
		vector <int> zostalo;
		for(int i = 1; i <= n; ++i)
			zostalo.pb(tab[i]);
		if(m == 2)
			for(int i = 1; i <= n; ++i)
				zostalo.pb(tab[i]);
		res += solve(zostalo);
		printf("%lld\n", start - res);
		return 0;
	}
	
	for(int i = n; i >= 1; --i){
		suf[i] = 1;
		if(tab[i] == tab[i + 1])
			suf[i] += suf[i + 1];
	}
	
	if(n == 0){
		puts("0");
		return 0;
	}

	int s = 1, e = n;
	while(suf[s] + s < e + 1){
		if(tab[e] != tab[s])
			break;
		if(pref[e] + suf[s] < k)
			break;
		
		res += 1LL * (m - 1) * k;
		s += k - pref[e];
		e -= pref[e];
	}
	
	if(suf[s] + s > e){
		LL mid = 1LL * (e - s + 1) * (m - 2);
		res += (mid / k) * k;
		mid %= k;
		
		if(pref[e] + mid + suf[s] < k){
			printf("%lld\n", start - res);
			return 0;
		}
		
		int add = mid + pref[e] >= k ? k - mid : pref[e];
		
		s += k - add - mid;
		e -= add;
		res += k;
		
		vector <int> zostalo;
		for(int i = 1; i <= e; ++i)
			zostalo.pb(tab[i]);
		for(int i = s; i <= n; ++i)
			zostalo.pb(tab[i]);
		res += solve(zostalo);
	}
	
	printf("%lld\n", start - res);
	return 0;
}