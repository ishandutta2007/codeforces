#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

const LL MX = 1e9 + 7LL;
const int N = 3e5 + 7;

int n;
LL pref[N];
LL suf[N];
LL sum = 0LL;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%I64d", &pref[i]);
	sort(pref + 1, pref + n + 1);
	
	for(int i = n; i >= 1; --i)
		suf[i] = (suf[i + 1] + pref[i])%MX;
	for(int i = 1; i <= n; ++i)
		pref[i] += pref[i - 1],
		pref[i] %= MX;
	
	LL mnoz = 1LL;
	for(int i = 1; i < n; ++i){
		LL diff = suf[i + 1] - pref[n - i] + MX;
		diff %= MX;
		sum = (sum + diff * mnoz)%MX;
		mnoz *= 2LL;
		mnoz %= MX;
	}
	
	printf("%I64d\n", sum);
	return 0;
}